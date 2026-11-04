#!/usr/bin/env python3
"""Turn a McCode-main generated .c (OpenACC-capable) into one that ALSO builds with
OpenMP target offload, mutually exclusive with OpenACC:

    -DOPENACC    unchanged OpenACC build
    -DOMPTARGET  OpenMP 5 target build, relying on unified shared memory
    (neither)    unchanged CPU build

Deliberately NOT done: explicit deep maps, struct flattening, declare mapper.
Prototype of design doc PRs 1-5 (EPICURE_docs/03_OpenMP_design.md), applied to
generated code for testing only.

usage: make_omp.py in.c out.c
"""
import re
import sys

src = open(sys.argv[1]).read()


def once(s, old, new):
    assert s.count(old) == 1, f"expected exactly one match for: {old[:70]!r}"
    return s.replace(old, new)


# --- 1. macro block (design 1.1), placed after the _GNU_SOURCE/_POSIX defines ---------
MACROS = """/* ---- EPICURE OpenMP prototype: backend selection ---- */
#if defined(OPENACC) && defined(OMPTARGET)
#  error "OPENACC and OMPTARGET are mutually exclusive"
#endif
#if defined(OPENACC) || defined(OMPTARGET)
#  define MCGPU 1
#endif
#ifdef OMPTARGET
#  include <omp.h>
#  pragma omp requires unified_shared_memory
#endif
/* ---- */

"""
head, sep, body = src.partition('#define MCCODE_STRING')
assert sep
src = head + MACROS + sep + body
split_at = len(head) + len(MACROS)  # leave the top-of-file "#ifndef OPENACC / _GNU_SOURCE" alone
head, body = src[:split_at], src[split_at:]

# --- 2. "device build" guards: OPENACC -> MCGPU, except OpenACC-API blocks -------------
lines = body.split('\n')
guard = re.compile(r'^(\s*#\s*if(?:n)?def\s+)OPENACC\b')
renamed = kept = 0
for k, ln in enumerate(lines):
    if guard.match(ln):
        nxt = lines[k + 1] if k + 1 < len(lines) else ''
        if re.search(r'\bacc_\w+\s*\(', nxt):   # acc_attach() etc: OpenACC API only
            kept += 1
            continue
        lines[k] = guard.sub(r'\1MCGPU', ln)
        renamed += 1
    elif 'defined(OPENACC)' in ln and not ln.lstrip().startswith('/*') and '#error' not in ln:
        lines[k] = ln.replace('defined(OPENACC)', 'defined(MCGPU)')
        renamed += 1
body = '\n'.join(lines)
body = body.replace('#include <openacc.h>', '#ifdef OPENACC\n#include <openacc.h>\n#endif')
body = once(body, '#include <accelmath.h>\n#else\n#include <math.h>',
            '#ifdef OPENACC\n#include <accelmath.h>\n#else\n#include <math.h>\n#endif\n#else\n#include <math.h>')

# --- 3. stacked OpenMP twins of the OpenACC data/atomic directives (design 1.2) -------
twins = {}


def twin(m):
    ind, rest = m.group(1), m.group(2).strip()
    if rest.startswith('atomic'):
        omp = 'omp ' + rest                                     # same clause, 1:1
    elif rest.startswith('declare create'):
        omp = 'omp declare target' + re.sub(r'\s+', '', rest[len('declare create'):])
    elif rest.startswith('update device'):
        omp = 'omp target update to' + rest[len('update device'):].strip()
    elif rest.startswith('update host'):
        omp = 'omp target update from' + rest[len('update host'):].strip()
    elif rest.startswith('parallel loop'):                     # raytrace_all, funnel, sort_absorb_last
        omp = 'omp target teams loop'                           # USM: no map clauses needed
    else:
        return m.group(0)                                       # routine, loop seq/independent, shape: none
    twins[omp.split('(')[0]] = twins.get(omp.split('(')[0], 0) + 1
    return f'{m.group(0)}\n{ind}#pragma {omp}'


body = re.sub(r'^([ \t]*)#pragma acc (.*)$', twin, body, flags=re.M)
# OpenMP wants declare target before the first use; '&_instrument_var' in the next line is one
body = once(body, '} _instrument_var;\nstruct _instrument_struct *instrument = & _instrument_var;\n',
            '} _instrument_var;\n#pragma omp declare target(_instrument_var)\nstruct _instrument_struct *instrument = & _instrument_var;\n')
body = once(body, '#pragma acc declare create ( _instrument_var )\n#pragma omp declare target(_instrument_var)\n',
            '#pragma acc declare create ( _instrument_var )\n')

# --- 4. Single_crystal: single-pass search+select on device (design PR 5) ----------
# Stock math, unchanged; only the selected reflection is kept, chosen by a weighted
# reservoir draw (P_j = refl_j / sum refl). Removes the per-thread
# T[MCSX_REFL_SLIST_SIZE] (168 B each) from the device stack. CPU path is stock.
# NUMERICAL CHANGE (device only): one extra random number per reachable reflection.
s0 = body.index('  hkl_search (struct hkl_data* L, void* TT')
s1 = body.index('} /* end hkl_search */', s0) + len('} /* end hkl_search */')
fn = body[s0:s1]
fn = once(fn, 'hkl_search (struct hkl_data* L, void* TT, int count, double V0, double kix, double kiy, double kiz, double tau_max, double* coh_refl, double* coh_xsect) {',
          'hkl_search_select (struct hkl_data* L, struct tau_data* Tsel, int count, double V0, double kix, double kiy, double kiz, double tau_max, double* coh_refl, double* coh_xsect, _class_particle* _particle) {')
fn = once(fn, 'struct tau_data* T = (struct tau_data*)TT;', 'struct tau_data Tj; double total = 0; int sel = -1;')
fn = fn.replace('T[j].', 'Tj.')
fn = once(fn, '        *coh_xsect += Tj.xsect;\n        j++;',
          '        *coh_xsect += Tj.xsect;\n'
          '        total += Tj.refl;\n'
          '        if (sel < 0 || rand0max (total) < Tj.refl) { *Tsel = Tj; sel = j; } /* sel<0: guard rand01()==1.0 */\n'
          '        j++;')
fn = fn.replace('} /* end hkl_search */', '} /* end hkl_search_select */')
body = body[:s1] + '\n\n  #ifdef MCGPU\n  int\n' + fn + '\n  #endif\n' + body[s1:]

body = once(body, '  struct tau_data T[MCSX_REFL_SLIST_SIZE];\n',
            '  struct tau_data T[1]; /* EPICURE: only the selected reflection, see hkl_search_select */\n')
body = once(body, '            tau_count = hkl_search (L, T, hkl_info.count, hkl_info.V0, kix, kiy, kiz, tau_max, &coh_refl, &coh_xsect);',
            '            #ifdef MCGPU\n'
            '            tau_count = hkl_search_select (L, T, hkl_info.count, hkl_info.V0, kix, kiy, kiz, tau_max, &coh_refl, &coh_xsect, _particle);\n'
            '            #else\n'
            '            tau_count = hkl_search (L, T, hkl_info.count, hkl_info.V0, kix, kiy, kiz, tau_max, &coh_refl, &coh_xsect);\n'
            '            #endif')
body = once(body, '        j = hkl_select (T, tau_count, coh_refl, &sum, _particle);',
            '        #ifdef MCGPU\n'
            '        j = 0; /* already selected in hkl_search_select */\n'
            '        #else\n'
            '        j = hkl_select (T, tau_count, coh_refl, &sum, _particle);\n'
            '        #endif')

open(sys.argv[2], 'w').write(head + body)
print(f'guards renamed to MCGPU: {renamed}, kept as OPENACC (API): {kept}')
for k, v in sorted(twins.items()):
    print(f'  #pragma {k}: {v}')
