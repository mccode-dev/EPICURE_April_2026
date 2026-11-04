#!/usr/bin/env python3
"""Second layer on top of make_omp.py: make the OMPTARGET build run WITHOUT unified shared
memory (LUMI has no HSA_XNACK=1). CPU and OPENACC builds stay as make_omp.py left them.

  - no 'requires unified_shared_memory'
  - heap data: omp_target_alloc + omp_target_memcpy, device addresses kept in NEW struct
    members (*_d). Host pointers are never replaced, so 'target update' of the static
    component structs stays a plain bitwise copy in both directions.
  - device code reaches the heap only through *_d, with a flat row-major index
  - every transfer is listed, checked and fatal on failure; unsupported cases abort
  - no declare mapper, no struct flattening, no deep map clauses

usage: make_omp_maps.py ../B_main_usm/NMX_simplified_omp.c NMX_simplified_omp_maps.c
"""
import re
import sys

s = open(sys.argv[1]).read()


def once(t, old, new):
    assert t.count(old) == 1, f"expected exactly one match for: {old[:70]!r} ({t.count(old)})"
    return t.replace(old, new)


# --- 1. no USM; FUNNEL not ported (its particle buffers are heap too) ------------------
s = once(s, '#  pragma omp requires unified_shared_memory\n',
         '#  ifdef FUNNEL\n#    error "OMPTARGET without USM: FUNNEL is not ported"\n#  endif\n')

# --- 2. device compilation pass only: no libc calls left in device code -----------------
s = once(s, 'int noprintf();\n', '''int noprintf();
#if defined(OMPTARGET) && (defined(__AMDGCN__) || defined(__NVPTX__))
/* device pass: diagnostics compile away, so the device image needs no libc. Host pass untouched. */
#define printf(...) 0
#define free(p) ((void)0)
#define abs(x) ((x) < 0 ? -(x) : (x))
#endif
''')

# --- 3. MPI: pick the device with OpenMP calls, the block is OpenACC API -----------------
s = once(s, '  int num_devices = acc_get_num_devices(acc_device_nvidia);\n',
         '''  #ifdef OMPTARGET
  if (omp_get_num_devices() > 0) omp_set_default_device(mpi_node_rank % omp_get_num_devices());
  #else
  int num_devices = acc_get_num_devices(acc_device_nvidia);
''')
s = once(s, '    acc_set_device_type( acc_device_host );\n  }\n',
         '    acc_set_device_type( acc_device_host );\n  }\n  #endif\n')

# --- 4. kernel: real thread parallelism, sized by the existing --numgangs/--vecsize -------
# clang lowers 'target teams loop' containing calls to one thread per team.
a = s.index('void raytrace_all(unsigned long long ncount')
b = s.index('#pragma omp target teams loop', a)
s = (s[:b] + '#pragma omp target teams distribute parallel for num_teams(numgangs) thread_limit(vecsize)'
     + s[b + len('#pragma omp target teams loop'):])
loop = '  for (unsigned long long cloop=0; cloop<loops; cloop++) {\n'
c = s.index(loop, a)
s = s[:c] + ('  #ifdef OMPTARGET\n'
             '  mcmap_update_globals();\n'
             '  #endif\n') + s[c:]

# --- 5. monitors: new members + flat index in TRACE --------------------------------------
# type -> (array names, rows, cols); index as in create_darr2d(rows, cols)
MON = {'PSD_monitor': (['PSD_N', 'PSD_p', 'PSD_p2'], 'nx', 'ny'),
       'Divergence_monitor': (['Div_N', 'Div_p', 'Div_p2'], 'nh', 'nv'),
       'TOFLambda_monitor': (['TOFL_N', 'TOFL_p', 'TOFL_p2'], 'nt', 'nL'),
       'DivLambda_monitor': (['Div_N', 'Div_p', 'Div_p2'], 'nL', 'nh')}


def members(comp, names):
    return '#ifdef OMPTARGET\n' + ''.join(f'  {n};\n' for n in names) + '#endif\n'


def add_members(t, comp, names):
    end = f'}}; /* _struct_{comp}_parameters */'
    return once(t, end, members(comp, names) + end)


s = once(s, '#ifdef OMPTARGET\n#  include <omp.h>\n', '''#ifdef OMPTARGET
/* element (i,j) of a host DArray2d, seen from TRACE: device copy is flat row-major */
#  define MC2D(a, i, j, ncol) _comp->_parameters.a##_d[(long)(i) * (long)(ncol) + (j)]
#else
#  define MC2D(a, i, j, ncol) a[i][j]
#endif
#ifdef OMPTARGET
#  include <omp.h>
''')

for comp, (arrs, nr, nc) in MON.items():
    s = add_members(s, comp, [f'double *{x}_d' for x in arrs])
    t0 = s.index(f'void class_{comp}_trace(_class_{comp} *_comp')
    t1 = s.index(f'/* class_{comp}_trace */', t0)
    tr = s[t0:t1]
    # TOFLambda histograms as [j][i], the others as [i][j]
    tr, n = re.subn(r'\b(' + '|'.join(arrs) + r')\[([ij])\]\[([ij])\]',
                    lambda m: f'MC2D({m[1]}, {m[2]}, {m[3]}, {nc})', tr)
    assert n == 6, (comp, n)
    s = s[:t0] + tr + s[t1:]

# --- 6. Single_crystal --------------------------------------------------------------------
s = add_members(s, 'Single_crystal', ['struct hkl_data *hkl_list_d'])
s = once(s, '    L = hkl_list;\n',
         '    #ifdef OMPTARGET\n    L = _comp->_parameters.hkl_list_d;\n    #else\n    L = hkl_list;\n    #endif\n')

# --- 7. Monitor_nD ----------------------------------------------------------------------
s = once(s, '    double *Mon2D_Buffer;\n',
         '    double *Mon2D_Buffer;\n#ifdef OMPTARGET\n'
         '    double *Mon2D_N_d, *Mon2D_p_d, *Mon2D_p2_d, *Mon2D_Buffer_d;\n#endif\n')
s = once(s, '''	    double *Mon2D_N = Vars->Mon2D_N[i];
	    double *Mon2D_p = Vars->Mon2D_p[i];
	    double *Mon2D_p2 = Vars->Mon2D_p2[i];
''', '''	    #ifdef OMPTARGET
	    double *Mon2D_N = Vars->Mon2D_N_d + i*Vars->Coord_Bin[2];
	    double *Mon2D_p = Vars->Mon2D_p_d + i*Vars->Coord_Bin[2];
	    double *Mon2D_p2 = Vars->Mon2D_p2_d + i*Vars->Coord_Bin[2];
	    #else
	    double *Mon2D_N = Vars->Mon2D_N[i];
	    double *Mon2D_p = Vars->Mon2D_p[i];
	    double *Mon2D_p2 = Vars->Mon2D_p2[i];
	    #endif
''')
s = once(s, '          double *Mon2D_Buffer = Vars->Mon2D_Buffer + buffer_slot*(Vars->Coord_Number+1);\n',
         '          #ifdef OMPTARGET\n'
         '          double *Mon2D_Buffer = Vars->Mon2D_Buffer_d + buffer_slot*(Vars->Coord_Number+1);\n'
         '          #else\n'
         '          double *Mon2D_Buffer = Vars->Mon2D_Buffer + buffer_slot*(Vars->Coord_Number+1);\n'
         '          #endif\n')

# --- 8. transfer layer -------------------------------------------------------------------
inst = re.findall(r'^_class_(\w+) _(\w+)_var;$', s, flags=re.M)
inst = [(t, n) for t, n in inst if t != 'particle']
assert len(inst) == 87, len(inst)
of = lambda typ: [n for t, n in inst if t == typ]

fn = []
for comp, (arrs, nr, nc) in MON.items():
    P = 'c->_parameters.'
    size = f'(size_t){P}{nr} * (size_t){P}{nc} * sizeof(double)'
    up = ''.join(f'  {P}{x}_d = mcmap_up(c->_name, "{x}", {P}{x}[0], b);\n  mcmap_poison(&{P}{x});\n' for x in arrs)
    dn = ''.join(f'  mcmap_down(c->_name, "{x}", {P}{x}[0], {P}{x}_d, b);\n  omp_target_free({P}{x}_d, mcmap_dev);\n' for x in arrs)
    fn.append(f'static void mcmap_up_{comp}(_class_{comp} *c) {{\n  size_t b = {size};\n{up}}}\n'
              f'static void mcmap_down_{comp}(_class_{comp} *c) {{\n  size_t b = {size};\n{dn}}}\n')

calls_up, calls_dn = [], []
for comp in MON:
    calls_up += [f'  mcmap_up_{comp}(&_{n}_var);\n' for n in of(comp)]
    calls_dn += [f'  mcmap_down_{comp}(&_{n}_var);\n' for n in of(comp)]
for n in of('Single_crystal'):
    calls_up.append(f'  mcmap_up_hkl(_{n}_var._name, &_{n}_var._parameters.hkl_list, &_{n}_var._parameters.hkl_list_d, _{n}_var._parameters.hkl_info.count);\n')
    calls_dn.append(f'  omp_target_free(_{n}_var._parameters.hkl_list_d, mcmap_dev);\n')
for n in of('Monitor_nD'):
    calls_up.append(f'  mcmap_up_nD(_{n}_var._name, &_{n}_var._parameters.Vars);\n')
    calls_dn.append(f'  mcmap_down_nD(_{n}_var._name, &_{n}_var._parameters.Vars);\n')
guards = [f'  if (_{n}_var._parameters.reflect[0]) mcmap_die("reflect table is host heap, not transferred", _{n}_var._name, "reflect");\n' for n in of('Guide_m')]
guards += [f'  if (_{n}_var._parameters.guideInfo.enableSegments) mcmap_die("guide segments are host heap, not transferred", _{n}_var._name, "segLength");\n' for n in of('Elliptic_guide_gravity')]
checks = ''.join(f'''  {{ int count = -1, h = -9999;
    #pragma omp target map(from: count, h)
    {{ count = _{n}_var._parameters.hkl_info.count; h = _{n}_var._parameters.hkl_list_d[count-1].h; }}
    if (count != mcmap_hkl_count || h != mcmap_hkl_h) mcmap_die("device readback differs from host", _{n}_var._name, "hkl_list");
    if (MCMAP_MASTER) printf("[mcmap] device readback ok: %s count=%d last h=%d\\n", _{n}_var._name, count, h);
  }}
''' for n in of('Single_crystal'))
structs = ' + '.join(f'sizeof(_{n}_var)' for _, n in inst)

LAYER = r'''#ifdef OMPTARGET
/* ---- EPICURE: explicit device memory, no USM. See make_omp_maps.py. ---- */
#ifdef MCMAP_HOST_TEST
/* Local test only: host stand-ins (macOS libomp has no libomptarget). Host pointers are
   poisoned during the run, which is what they are on the device: unusable. */
#define omp_target_alloc(b, d) malloc(b)
#undef free
#define omp_target_free(p, d) free(p)
#define omp_target_memcpy(dst, src, n, dof, sof, dd, sd) (memcpy((char *)(dst) + (dof), (char *)(src) + (sof), (n)), 0)
static struct { void **slot; void *val; } mcmap_ps[256];
static int mcmap_np;
static void mcmap_poison(void *slot) {
  void **p = slot;
  if (*p) { mcmap_ps[mcmap_np].slot = p; mcmap_ps[mcmap_np++].val = *p; *p = (void *)0x10; }
}
#else
#define mcmap_poison(slot) ((void)0)
#endif
#ifdef USE_MPI
#define MCMAP_MASTER (mpi_node_rank == mpi_node_root)
#else
#define MCMAP_MASTER 1
#endif
static int mcmap_dev, mcmap_host, mcmap_hkl_count, mcmap_hkl_h;
static size_t mcmap_up_total, mcmap_down_total;

static void mcmap_die(const char *why, const char *comp, const char *what) {
  printf("[mcmap] FATAL: %s (%s.%s)\n", why, comp, what);
  fflush(stdout);
  abort(); /* not exit(): that is a macro here in GPU builds */
}
static void *mcmap_up(const char *comp, const char *what, const void *h, size_t b) {
  void *d = omp_target_alloc(b, mcmap_dev);
  if (!d) mcmap_die("omp_target_alloc failed", comp, what);
  if (omp_target_memcpy(d, (void *)h, b, 0, 0, mcmap_dev, mcmap_host)) mcmap_die("copy to device failed", comp, what);
  mcmap_up_total += b;
  if (MCMAP_MASTER) printf("[mcmap] to device   %-24s %-13s %12zu B\n", comp, what, b);
  return d;
}
static void mcmap_down(const char *comp, const char *what, void *h, void *d, size_t b) {
  if (omp_target_memcpy(h, d, b, 0, 0, mcmap_host, mcmap_dev)) mcmap_die("copy from device failed", comp, what);
  mcmap_down_total += b;
  if (MCMAP_MASTER) printf("[mcmap] from device %-24s %-13s %12zu B\n", comp, what, b);
}
/* Monitor_nD rows are separate mallocs on the host, one flat block on the device */
static double *mcmap_up_rows(const char *comp, const char *what, double **rows, long nr, long nc) {
  size_t rb = nc * sizeof(double);
  double *tmp = malloc(nr * rb), *d;
  if (!tmp) mcmap_die("malloc failed", comp, what);
  for (long i = 0; i < nr; i++) memcpy(tmp + i * nc, rows[i], rb);
  d = mcmap_up(comp, what, tmp, nr * rb);
  free(tmp);
  return d;
}
static void mcmap_down_rows(const char *comp, const char *what, double **rows, double *d, long nr, long nc) {
  size_t rb = nc * sizeof(double);
  double *tmp = malloc(nr * rb);
  if (!tmp) mcmap_die("malloc failed", comp, what);
  mcmap_down(comp, what, tmp, d, nr * rb);
  for (long i = 0; i < nr; i++) memcpy(rows[i], tmp + i * nc, rb);
  free(tmp);
  omp_target_free(d, mcmap_dev);
}
static void mcmap_up_hkl(const char *comp, struct hkl_data **h, struct hkl_data **d, int count) {
  if (count < 1) mcmap_die("empty reflection list", comp, "hkl_list");
  *d = mcmap_up(comp, "hkl_list", *h, count * sizeof(struct hkl_data));
  mcmap_hkl_count = count;
  mcmap_hkl_h = (*h)[count - 1].h;
  mcmap_poison(h);
}
static void mcmap_up_nD(const char *comp, MonitornD_Variables_type *V) {
  if (V->Flag_Auto_Limits) mcmap_die("auto limits need host realloc, give explicit limits", comp, "Vars");
  if (V->Flag_Multiple && V->Mon2D_N) mcmap_die("n1D histograms not ported", comp, "Vars");
  if (V->Mon2D_N) {
    V->Mon2D_N_d  = mcmap_up_rows(comp, "Mon2D_N",  V->Mon2D_N,  V->Coord_Bin[1], V->Coord_Bin[2]);
    V->Mon2D_p_d  = mcmap_up_rows(comp, "Mon2D_p",  V->Mon2D_p,  V->Coord_Bin[1], V->Coord_Bin[2]);
    V->Mon2D_p2_d = mcmap_up_rows(comp, "Mon2D_p2", V->Mon2D_p2, V->Coord_Bin[1], V->Coord_Bin[2]);
    mcmap_poison(&V->Mon2D_N); mcmap_poison(&V->Mon2D_p); mcmap_poison(&V->Mon2D_p2);
  }
  if (V->Mon2D_Buffer) {
    V->Mon2D_Buffer_d = mcmap_up(comp, "Mon2D_Buffer", V->Mon2D_Buffer, (V->Coord_Number + 1) * V->Buffer_Block * sizeof(double));
    mcmap_poison(&V->Mon2D_Buffer);
  }
}
static void mcmap_down_nD(const char *comp, MonitornD_Variables_type *V) {
  if (V->Mon2D_N) {
    mcmap_down_rows(comp, "Mon2D_N",  V->Mon2D_N,  V->Mon2D_N_d,  V->Coord_Bin[1], V->Coord_Bin[2]);
    mcmap_down_rows(comp, "Mon2D_p",  V->Mon2D_p,  V->Mon2D_p_d,  V->Coord_Bin[1], V->Coord_Bin[2]);
    mcmap_down_rows(comp, "Mon2D_p2", V->Mon2D_p2, V->Mon2D_p2_d, V->Coord_Bin[1], V->Coord_Bin[2]);
  }
  if (V->Mon2D_Buffer) {
    /* Buffer_Counter arrived with 'target update from' of the component struct */
    unsigned long n = V->Buffer_Counter < V->Buffer_Block ? V->Buffer_Counter : V->Buffer_Block;
    if (V->Buffer_Counter >= V->Buffer_Block)
      printf("[mcmap] WARNING: %s list is full, %lu rows kept: events were lost. Raise the buffer or lower -n.\n", comp, n);
    mcmap_down(comp, "Mon2D_Buffer", V->Mon2D_Buffer, V->Mon2D_Buffer_d, n * (V->Coord_Number + 1) * sizeof(double));
    omp_target_free(V->Mon2D_Buffer_d, mcmap_dev);
  }
}
@FUNCS@
/* Called from raytrace_all(), after mcncount is sliced/rounded. Must stay here, above the
   '#define mcgravitation (_particle->mcgravitation)' of the TRACE section. mcseed is static
   and unused on the device: the seed is a kernel argument. */
static void mcmap_update_globals(void) {
  #pragma omp target update to(mcncount, mcrun_num, mcgravitation, mcdotrace)
}
/* end of init(), before the component structs go to the device */
static void mcmap_upload(void) {
  mcmap_host = omp_get_initial_device();
#ifdef MCMAP_HOST_TEST
  mcmap_dev = mcmap_host;
#else
  if (omp_get_num_devices() < 1) mcmap_die("no offload device found", "runtime", "omp_get_num_devices");
  mcmap_dev = omp_get_default_device();
#endif
  if (MCMAP_MASTER) printf("[mcmap] %d device(s), using %d, no unified memory\n", omp_get_num_devices(), mcmap_dev);
@GUARDS@@UP@  if (MCMAP_MASTER) printf("[mcmap] to device total %zu B heap, %zu B component structs\n", mcmap_up_total, (size_t)(@STRUCTS@));
}
/* after the 'target update to' list of init(): prove that structs and heap copies agree */
static void mcmap_check(void) {
  #pragma omp target
  { instrument = &_instrument_var; }
@CHECKS@}
/* after the 'target update from' list of finally(), before save() */
static void mcmap_download(void) {
#ifdef MCMAP_HOST_TEST
  while (mcmap_np) { mcmap_np--; *mcmap_ps[mcmap_np].slot = mcmap_ps[mcmap_np].val; }
#endif
@DOWN@  if (MCMAP_MASTER) printf("[mcmap] from device total %zu B heap\n", mcmap_down_total);
}
#endif /* OMPTARGET */

'''
LAYER = (LAYER.replace('@FUNCS@', ''.join(fn)).replace('@GUARDS@', ''.join(guards))
         .replace('@UP@', ''.join(calls_up)).replace('@DOWN@', ''.join(calls_dn))
         .replace('@STRUCTS@', structs).replace('@CHECKS@', checks))
s = once(s, 'int init(void) { /* called by mccode_main', LAYER + 'int init(void) { /* called by mccode_main')
s = once(s, '#ifdef MCGPU\n#ifdef OPENACC\n#include <openacc.h>\n#endif\n#pragma acc update device(_Origin_var)\n',
         '#ifdef OMPTARGET\n  mcmap_upload();\n#endif\n#ifdef MCGPU\n#ifdef OPENACC\n#include <openacc.h>\n#endif\n#pragma acc update device(_Origin_var)\n')
s = once(s, '#pragma omp target update to(_instrument_var)\n',
         '#pragma omp target update to(_instrument_var)\n#ifdef OMPTARGET\n  mcmap_check();\n#endif\n')
s = once(s, '#pragma omp target update from(_instrument_var)\n',
         '#pragma omp target update from(_instrument_var)\n#ifdef OMPTARGET\n  mcmap_download();\n#endif\n')

# --- 9. Single_crystal: no reflection list, in ALL builds --------------------------------
# hkl_search_select is the only selection, on CPU too. Gone: tau_list, T[], hkl_search,
# hkl_select, MCSX_REFL_SLIST_SIZE and its cap, and the CPU SPLIT reuse cache (it restored a
# list; without one every SPLIT iteration searches again and draws its own reflection).
# NUMERICAL CHANGE (all builds): every reachable reflection counts, stock stops at the cap;
# the random stream differs from stock after the crystal.
def cut(t, a, b):
    """remove from the start of a up to the start of b"""
    assert t.count(a) == 1, a
    i = t.index(a)
    return t[:i] + t[t.index(b, i):]


s = once(s, '  #ifndef MCSX_REFL_SLIST_SIZE\n  #define MCSX_REFL_SLIST_SIZE 128\n  #endif\n\n', '')
s = once(s, ' * CFLAGS=  -DMCSX_REFL_SLIST_SIZE=1024  @NCRYSTALFLAGS@', ' * CFLAGS=  @NCRYSTALFLAGS@')
s = cut(s, '  /* hkl_search\n    search the HKL', '  #ifdef MCGPU\n  int\n  hkl_search_select')
s = once(s, '  #ifdef MCGPU\n  int\n  hkl_search_select', '''  /* hkl_search_select
    search the HKL reflections which are on the Ewald sphere, and keep one of them,
    chosen with P_j = refl_j / sum refl by a weighted reservoir draw.
    returns tau_count; updates coh_refl, coh_xsect and *Tsel
   */
  #pragma acc routine
  int
  hkl_search_select''')
s = once(s, '''      /*protect against tau shortlist buffer overrrun*/
      if (j == MCSX_REFL_SLIST_SIZE) {
        break;
      }
''', '')
s = once(s, '  } /* end hkl_search_select */\n  #endif\n', '  } /* end hkl_search_select */\n')
s = cut(s, '\n  #pragma acc routine\n  int\n  hkl_select (struct tau_data* T', '\n  /* Functions for "reorientation", powder and PG modes */')
s = once(s, '  struct tau_data  tau_list[MCSX_REFL_SLIST_SIZE];\n', '')
s = s.replace('  #define tau_list (_comp->_parameters.tau_list)\n', '').replace('  #undef tau_list\n', '')
s = cut(s, '                      #ifndef MCGPU\n  struct tau_data* T;', '  struct tau_data T[1];')
s = once(s, '  struct tau_data T[1]; /* EPICURE: only the selected reflection, see hkl_search_select */\n  #endif\n',
         '  struct tau_data T[1]; /* EPICURE: only the selected reflection, see hkl_search_select */\n')
s = once(s, '    #ifndef MCGPU\n    T = tau_list;\n    hkl_info.type = type;\n', '    #ifndef MCGPU\n    hkl_info.type = type;\n')
a = '        #ifndef MCGPU\n        /* in case we use \'SPLIT\''
b = '      } else {\n        // When extra_order used'
assert s.count(a) == 1
i = s.index(a)
s = s[:i] + '''        /* Max possible tau for this ki with 5*sigma delta-d/d cutoff. */
        double tau_max = 2 * ki / (1 - 5 * hkl_info.m_delta_d_d);

        tau_count = hkl_search_select (L, T, hkl_info.count, hkl_info.V0, kix, kiy, kiz, tau_max, &coh_refl, &coh_xsect, _particle);
''' + s[s.index(b, i):]
s = cut(s, '        sum = 0;\n        #ifdef MCGPU\n        j = 0; /* already selected', '        i = T[j].index;\n')
s = once(s, '        i = T[j].index;\n', '        j = 0; /* already selected in hkl_search_select */\n        i = T[j].index;\n')
s = cut(s, '    /* in case this instance is used in a SPLIT, we can recommend the\n', '    #ifdef USE_OPENCL\n    if (oclContext_SX')

open(sys.argv[2], 'w').write(s)
print(f'{len(inst)} instances; {len(calls_up)} heap uploads; {len(guards)} guards')
