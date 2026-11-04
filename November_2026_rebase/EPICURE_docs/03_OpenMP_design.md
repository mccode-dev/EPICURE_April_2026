# Design: OpenMP 5 target offload next to OpenACC, starting fresh from `main`

## 0. Principles

- **One generated `.c`, two backends, chosen at compile time and mutually exclusive.**
  `-DOPENACC` or `-DOMPTARGET`. Never both; `#error` if both are set. CPU builds stay unchanged.
- **Components stay single-source.** Don't fork them and don't add a pragma DSL. OpenMP sits
  next to OpenACC, line for line.
- **Explicit deep maps are required on LUMI.** `HSA_XNACK=1` is not available there, so
  unified shared memory (USM) cannot carry heap data on the MI250X. USM stays useful only as a
  shortcut on hardware that has it (NVIDIA with HMM, GH200, MI300A). See §3.
- **Don't port** struct flattening, hard-coded team sizes, or debug counters. `declare mapper` stays
  off the plan too, unless CCE turns out to support it (§3)
  (see `01_summary.md`, "Tried and dropped").

## 1. How the two backends live side by side

### 1.1 Macros (one block, emitted at the top of every generated file)

```c
#if defined(OPENACC) && defined(OMPTARGET)
#  error "OPENACC and OMPTARGET are mutually exclusive"
#endif
#if defined(OPENACC) || defined(OMPTARGET)
#  define MCGPU 1      /* "device build": printf nullification, no OFF, no signals, ... */
#endif
#ifdef OMPTARGET
#  include <omp.h>
#  ifdef OMPTARGET_USM                         /* not on LUMI, see §3 */
#    pragma omp requires unified_shared_memory
#  endif
#endif
```

`OPENACC` keeps a single meaning: the OpenACC API (`openacc.h`, `accelmath.h`, `acc_attach`).
That is 18 sites in 7 files. **Every other `#ifdef OPENACC` means "device build" and becomes
`MCGPU`.** Why not `_OPENMP`: the compiler defines it for any `-fopenmp` build, including
host-only ones.

### 1.2 Directive mapping

| OpenACC (stays) | OpenMP (added) | Where |
|---|---|---|
| `#pragma acc routine [seq]` | **nothing.** Implicit declare target, single TU (OpenMP ≥ 5.0). Shown to work in 04. | 987 sites, untouched |
| `#pragma acc atomic [update\|read\|write\|capture]` | `#pragma omp atomic [same]` on the **next line** | 411 sites / 91 files |
| `#pragma acc declare create(list)` | `#pragma omp declare target(list)` on the next line | 295 / 171 files |
| `#pragma acc update device(x)` / `host(x)` | `#pragma omp target update to(x)` / `from(x)` | 68 / 57 files plus the code generator |
| `#pragma acc parallel loop …` (code generator) | `#pragma omp target teams distribute parallel for num_teams(numgangs) thread_limit(vecsize)`. **Not `target teams loop`:** clang lowers that to one thread per team when the body contains calls. Seen in device IR. | code generator |
| `#pragma acc loop independent` (`SPLIT`, code generator) | nothing (already inside the kernel) | code generator |

**Stacked pragmas, not macros.** Each compiler ignores the other's pragma, and 04 already
compiled and ran with 124 leftover `#pragma acc` lines. The rewrite is mechanical, needs no
new abstraction, and `_Pragma` portability (MSVC, nvc) stops mattering. CI enforces it with a
single check:

```bash
git ls-files '*.comp' '*.c' '*.h' | xargs awk '/#pragma acc (atomic|declare create|update)/{p=FILENAME":"FNR; next} p{if ($0 !~ /#pragma omp/) print "missing omp twin: " p; p=""}' | tee /dev/stderr | (! grep -q .)
```

If the warnings about ignored foreign pragmas become noise, swap in `MC_ATOMIC(kind)` macros
later. ponytail: stacked pragmas double the line count at 774 sites; macros are the upgrade
path if warnings or readability bite.

### 1.3 Code generator (`cogen.c.in`)

There are about 20 hard-coded `acc` emission sites and 24 `OPENACC` guards. Add a single helper:

```c
static void cout_pragma(char *acc, char *omp) {
  cout("#if defined(OPENACC)");   coutf("#pragma acc %s", acc);
  cout("#elif defined(OMPTARGET)"); coutf("#pragma omp %s", omp);
  cout("#endif");
}
```
Route every site through it:

| Site | OpenMP form |
|---|---|
| `declare create(_X_var)`, `(_instrument_var)`, `(instrument)` | `declare target(_X_var)` … |
| end of INITIALISE: `update device(_X_var)` per component plus instrument | `target update to(_X_var)` |
| start of FINALLY: `update host(_X_var)` | `target update from(_X_var)` |
| `raytrace_all`: `parallel loop num_gangs() vector_length()` | `target teams distribute parallel for num_teams(numgangs) thread_limit(vecsize)` |
| funnel kernels: `parallel loop present(particles[0:n])` | `target teams loop map(tofrom: particles[0:n])`; better, one enclosing `target data map(alloc:…)` plus updates at CPU-only segments |
| `SPLIT`: `loop independent` | omit |
| the `routine` lines | omit |

Then `s/#ifdef OPENACC/#ifdef MCGPU/` in the code generator wherever "device build" is meant.

**Parity**: `mccode-antlr` (the Python code generator) has to get the same emission change.

## 2. Plan for a fresh start: small PRs, each green on Linux, macOS and Windows

| # | PR | Behaviour change? | Comes from |
|---|---|---|---|
| 1 | **Macro block plus `OPENACC`→`MCGPU`** in the code generator, runtime, components and libraries. A bulk script with `--dry-run` first (AGENTS.md §9); API sites stay on `OPENACC`. Check: the preprocessed output for `-DOPENACC` and for the CPU build is identical before and after (`cc -E`). | none | pwhacks guards, done right |
| 2 | **Code generator `cout_pragma` plus OMP twins** of the ~20 sites. Same check for the ACC and CPU builds. | none for existing builds | pwhacks cogen, 04 kernel form |
| 3 | **Runtime**: `declare target` on `mcseed`, `mcgravitation`, `mcdotrace`, `mcncount`, `mcrun_num` (twins of the existing `acc declare create`); `<omp.h>` placed correctly. | none | pwhacks `mccode-r.c` |
| 4 | **Components and libraries**: stacked `omp atomic`, `omp declare target` and `omp target update` (bulk script plus CI check). | none | pwhacks comps, 04 monitors |
| 5 | **Single_crystal single-pass selection** (JS's reservoir draw) with 04 findings 1–3 fixed. Removes the per-thread `T[MCSX_REFL_SLIST_SIZE]` stack array **for OpenACC as well**. On the CPU `SPLIT` cache, drop the cache rather than special-casing it: one code path. **Flag: numerical change** (RNG stream). Needs a χ² comparison with the old version on `Test_Single_crystal` and templateNMX. | **yes**, statistical only | 02/04 |
| 6 | **Build plumbing**: `OMPFLAGS` in `PlatformDefaults.cmake` / the toolchains / `mccode_config.json.in`, plus `mcrun --openmp`. The MPI branch must not use the NVIDIA-only `-acc_gpu_bind` wrapper. Defaults: CCE `-fopenmp -DOMPTARGET`; clang `-fopenmp --offload-arch=… -DOMPTARGET`; nvc `-mp=gpu -DOMPTARGET` (add `-gpu=mem:unified -DOMPTARGET_USM` where HMM exists). | none | Makefiles in EPICURE |
| 6b | **Explicit maps** (§3): contiguous Monitor_nD arrays, flat device indexing in the monitors, and a per-component map list emitted by the code generator. **Required for LUMI.** | flat indexing must stay bit-identical on CPU | 04 / variant A |
| 7 | **Validation**: Minimal, templateNMX and NMX_simplified (stock instrument, `main` components) on CPU, OpenACC and OpenMP, nvc and CCE. Same `-n` / `--seed` / `-np`, compared monitor by monitor. | n/a | 04 |

Until PR 6 lands you can test with `mcrun --openacc --override-config=<dir>` where `OACCFLAGS`
holds the OpenMP flags. **That needs no code**, but it is single-rank only, because of the
`acc_gpu_bind` wrapper.

PRs 1–4 are behaviour-neutral and can be reviewed by diffing the preprocessed output. PR 5 is
the only physics-adjacent one and stands alone; it is worth doing even if OpenMP stalls. PR 6b
is the largest piece and the one LUMI depends on.

## 3. Data movement: explicit maps on LUMI, USM only as a shortcut elsewhere

**The constraint.** `HSA_XNACK=1` is not available on LUMI. Without it the MI250X cannot fault
on ordinary `malloc` memory, so a host heap pointer is not valid on the device. That rules out
`#pragma omp requires unified_shared_memory` there. An earlier version of this document made
USM the first phase on the assumption that XNACK could be enabled. That assumption was wrong.

**What this means for each approach:**

| Approach | On LUMI | Evidence |
|---|---|---|
| Device allocations with `*_d` struct members (variant B2) | **Recommended.** Built from current `main`, no attach semantics, no map clauses | Host runs with poisoned host pointers agree with stock `main`. Device compile for gfx90a. No GPU run yet. |
| Explicit deep maps (04 / variant A) | Fits the hardware | Hand-written for NMX by JS; the repo does not record which hardware it ran on (open question for JS). Fixed variant A checked on host fallback only. |
| USM (variant B) | Not usable | Host-fallback check only, which never touches device memory |
| Struct flattening | Still not needed by the OpenMP rules: an inline nested struct maps by value with its parent | **Not yet shown on a GPU.** Earlier explicit-map runs used flattened structs (pwhacks code generator). B2 keeps `_parameters`, so a B2 run on LUMI settles this. |
| `declare mapper` | Fails on nvc (`d27d752`). Not known on CCE. | Worth one small test on CCE: it would remove the need for the hook below. |

**What the explicit path needs.** For NMX, 10 of the 87 component instances hold heap data that
TRACE uses: 5 sample monitors, Single_crystal (`hkl_list`), 3 list-mode Monitor_nD
(`Mon2D_Buffer`) and the 2D Monitor_nD. Everything else maps as a plain struct.

1. **Contiguous storage.** `create_darr2d` already is. Monitor_nD on `main` is one `malloc` per row (B7).
2. **Flat device indexing**, `X[0][i*ny+j]`, so no pointer table has to exist on the device. This is
   the row-major form from variant A's fix 4. Bit-identical on the CPU by construction.
3. **Array extents.** The code generator does not know them, so components must state them. Two options:
   - **Map list in the component** (a DSL and grammar change), emitted verbatim per instance:
     ```
     %{ MCGPU_MAP: PSD_N[0][0:nx*ny], PSD_p[0][0:nx*ny], PSD_p2[0][0:nx*ny] %}
     ```
   - **Plain C, no grammar change**: a per-component function in `SHARE`, called by the code generator
     after INITIALIZE and before FINALLY. Needs a naming convention only. B2 is a working
     prototype: `omp_target_alloc` and device addresses in separate struct members, which needs
     no pointer attachment and survives `target update from` of the struct.

   Recommendation: try the plain-C option first, since it leaves the grammar and `mccode-antlr`
   parsing alone. A component with heap data and no map function must fail at compile time for
   `OMPTARGET`, never at run time.
4. **Coverage.** Every GPU-capable component with heap data used in TRACE needs this, not just
   the 10 in NMX. That audit has not been done. Start with the NMX set, and make the others
   refuse to build for `OMPTARGET` until they are converted.
5. **FUNNEL**: one `target data map(alloc: particles[0:n])` around the batch loop, with updates
   only at CPU-only segments, instead of a transfer per kernel (04 finding 8).

**An untested alternative that would avoid deep maps:** allocate component heap data in
device-accessible pinned host memory, through a runtime wrapper around `malloc`. As far as I
know this does not depend on XNACK, but it is vendor-specific in OpenMP
(`llvm_omp_target_alloc_host` or `hipHostMalloc`), I have not checked it on CCE, and monitor
atomics would cross the host link and could be slow. Worth a small LUMI test only if the
explicit route proves too costly.

## 4. Blockers on current `main`

| # | Blocker | Size | Fixed by |
|---|---|---|---|
| B1 | `OPENACC` means both "device build" and "OpenACC API"; there is no neutral macro | 208 sites / 68 files + 24 in the code generator | PR 1 |
| B2 | Atomics exist only as `acc` | 411 / 91 files | PR 4 |
| B3 | Globals: `acc declare create` and `acc update` with no OpenMP twin | 295 / 171 + 68 / 57 | PRs 3, 4 |
| B4 | The code generator hard-codes about 20 `acc` emissions | 1 file | PR 2 |
| B5 | **Single_crystal per-thread `T[MCSX_REFL_SLIST_SIZE]` on the device stack** (168 B × 1024 ≈ 172 kB per thread for NMX). AMD's default device stack is far smaller, and it hurts OpenACC occupancy as well. | 1 component (+ `Single_crystal_process` for Union, to audit) | PR 5 |
| B6 | No `OMPFLAGS` / `--openmp`. `--openacc` with MPI calls the NVIDIA-only `acc_gpu_bind`. The generated device selection under `USE_MPI` is OpenACC API only (`acc_get_num_devices`), so it does not compile for OpenMP. | tools + cmake + runtime | PR 6 |
| B7 | Monitor_nD 2D histograms are one `malloc` per row (not contiguous) | 1 lib | PR 6b |
| B12 | **No USM on LUMI**, so nothing tells the device how large component heap data is. Needs a per-component map list, flat device indexing, and an audit of all GPU-capable components. This is the largest blocker. | all components with heap data used in TRACE | PR 6b |
| B8 | `mccode-antlr` parity | other repo | follows PR 2 |
| B10 | `main`'s Single_crystal now `%include`s `mccode-ncrystal-lib` (`DEPENDENCY "@NCRYSTALFLAGS@"`), so NCrystal is a **link-time dependency** on the GPU machine as well. `mcstas -t` leaves `@NCRYSTALFLAGS@` unexpanded in the `CFLAGS=` header line; only mcrun expands it. | LUMI env | `pip install ncrystal`, or guard it out under `MCGPU` |
| B11 | The code generator emits `declare create(_instrument_var)` *after* `instrument = &_instrument_var`. OpenMP (clang) warns "declare target after first use". | 1 line | PR 2 |
| B13 | Device code calls libc `printf` (`DEBUG_*`, component diagnostics), `free` and `abs`. Device-side support differs per compiler. B2 removes them in the device pass, using `__AMDGCN__` / `__NVPTX__`. Whether CCE defines these is not verified; if not, the calls stay as they are in B. | runtime | PR 3 |
| B9 | Compiler maturity: `declare mapper` broken in nvc, `-O0` stack blow-ups in the funnel path, CCE behaviour unknown to me | — | avoid mappers; build at `-O2`; validate on both compilers |

**Not blockers**, contrary to what the EPICURE branches implied:
- Struct flattening: inline nested structs map by value (per the OpenMP rules; not yet demonstrated, see §3).
- `acc routine` removal: leave those lines in place, OpenMP doesn't need them.
- Monitor_nD list-mode race: already fixed on `main` with `atomic capture`.
- RNG seeding per ray, batch and rank: already reworked on `main`, and backend-neutral.

## 5. Open decisions

1. The macro name: `OMPTARGET` (proposed) or something else? It has to stay distinct from `_OPENMP`.
2. Explicit-map hook (§3): plain-C function per component (recommended) or a map list in the DSL?
3. PR 5: should the CPU `SPLIT` cache in Single_crystal be dropped for a single code path, at
   some CPU cost with `SPLIT>1`, measured on templateNMX?
