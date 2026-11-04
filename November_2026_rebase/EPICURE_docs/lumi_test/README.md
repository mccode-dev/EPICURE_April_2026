# NMX_simplified OpenMP test kit (LUMI)

These are three hand-made test variants of `04_NMX_simplified`. They are for testing only: no
commit, patch or PR.

**On LUMI, run B2 and A.** `HSA_XNACK=1` is not available there. B2 is current `main` with explicit,
checked transfers and no unified memory (next section). A is Joachim's 04 with fixes. B depends on
unified shared memory, so on LUMI it is a compile check only. Background: `../02_NMX_simplified_status.md` and `../03_OpenMP_design.md`.

## B2: `B2_main_maps/NMX_simplified_omp_maps.c`, the `main`-based LUMI build

`make_omp_maps.py` is a second layer on B's output. Rerun it after regenerating B. Built with `-DOMPTARGET`.

| What | How |
|---|---|
| No USM | The `requires unified_shared_memory` line is gone. |
| Static data (87 component structs, `_instrument_var`, run globals) | `declare target` plus `target update to/from`, as in B. 2.8 MB. |
| Heap data (10 instances) | `omp_target_alloc` + `omp_target_memcpy` at the end of `init()`. Device addresses go in **new** struct members (`PSD_N_d`, `hkl_list_d`, `Mon2D_Buffer_d`, ...). Host pointers stay as they are, so `target update` of a struct stays a plain copy in both directions, with no attach semantics to depend on. 1.48 GB up, nearly all of it the 3 list buffers. |
| TRACE | Reaches the heap only through `*_d`, flat row-major: `MC2D()` in the four monitors, `L = hkl_list_d` in Single_crystal, `Mon2D_*_d` in Monitor_nD. |
| After the run | In `finally()`: structs come back first, which brings `Buffer_Counter`. Then arrays come down before `save()`. List buffers transfer only the rows actually used. |
| Kernel | `target teams distribute parallel for num_teams(numgangs) thread_limit(vecsize)`. B's `target teams loop` lowers to one thread per team on clang when the body has calls. Size it with the existing `--numgangs` / `--vecsize` (default 7813 x 128). |
| Device code | No libc: in the device pass `printf`, `free` and `abs` compile away, so diagnostics from device code are silent. No indirect calls. |
| MPI | The device-selection block on `main` is OpenACC API only. An OpenMP version is added (`rank % omp_get_num_devices()`). |
| Not done | No deep map clauses, no `declare mapper`, no struct flattening. |

**Control.** Every transfer prints a `[mcmap]` line with component, array and bytes, plus totals. Every
allocation and copy is checked and aborts on failure. After the upload a small kernel reads
`hkl_info.count` and the last `hkl_list` entry back from the device and compares with the host, so a
broken transfer stops the job before the run. The job also **aborts** if there is no device (it
never falls back to the host), or for cases not ported: Monitor_nD auto limits or n1D, Guide_m with a
`reflect` table, Elliptic guide segments, and `-DFUNNEL` (compile error). A full list buffer prints a warning with the rows kept.

**Checked here** (macOS arm64, clang 21.1.8; no GPU, no CCE):

| Check | Result |
|---|---|
| Device compile, gfx90a and sm_80 | Passes. Only `__kmpc_*` and math-library symbols are left undefined; 0 calls to `printf`/`free`/`abs`; 0 indirect calls. |
| Device globals | Real globals now (`decl_tgt_ref_ptr` gone with `requires`); `instrument` statically holds the device address of `_instrument_var`. |
| Kernel form | Contains `__kmpc_parallel_*`, so threads within a team are used. |
| Stack | Largest frames: 3.9 kB kernel, 2.4 kB `raytrace`, 1.7 kB `class_Monitor_nD_trace`, so in the order of 10 kB per thread, against 172 kB on stock `main`. Indicative: math calls were not linked in. |
| 1e8 rays, 8 host threads, `-DMCMAP_HOST_TEST` | **0 flagged** by `compare.py` against stock `ref_cpu`. Before the crystal χ² = 0 (identical). After it z = +0.39, +0.18, −0.84, +0.39, χ²/dof 0.93, the same as B. Real concurrency on atomics and list slots: 34 s wall, 4m24 CPU. |
| Host pointers | In that test all host heap pointers are set to `0x10` during the run, which is what they are on the device: unusable. It completed. As negative controls, restoring one host pointer in device code (`hkl_list`, then `Mon2D_N`) segfaults each time, so the test does catch a missed pointer. |
| CPU and `-DOPENACC` builds | Preprocessed output equals B, apart from one `omp` pragma line that those builds ignore without `-fopenmp`. |
| `-DOMPTARGET -DUSE_MPI` | Compiles and links (host test mode). Not run. |

**Not checked, only LUMI can do it:** a real device run, CCE accepting all of this, the `target update`
of structs across a real host/device split (a no-op on the host test), timings. `-DMCMAP_HOST_TEST` swaps
the `omp_target_*` calls for host stand-ins because macOS `libomp` has no `libomptarget`.

## A and B

| | A: `A_04_fixed/` | B: `B_main_usm/` |
|---|---|---|
| Starting point | Joachim's `04_work_joachim` `NMX_simplified.c` (pwhacks code generator, Jun 4) | `mcstas` from current `main` (mccode-dev, 3.99.99 as of 2026-11-02) run on the same `.instr` → `NMX_simplified_main.c` |
| Changes | 4 output-changing bug fixes, marked `FIX(1..4)` in the source (below) | `make_omp.py` → `NMX_simplified_omp.c` (rerun it after regenerating) |
| Switch | `_OPENMP`, i.e. any `-fopenmp` | `-DOMPTARGET` (OpenMP) / `-DOPENACC` / neither (CPU). Mutually exclusive, `#error` if both are set. |
| Data movement | explicit deep maps (hand-written per instance), `declare target link` | **`#pragma omp requires unified_shared_memory`**; `declare target` plus `target update` twins of the OpenACC lines only. **No deep maps, no struct flattening, no `declare mapper`.** |
| Single_crystal | Joachim's refactor plus reservoir selection | Stock math; a device-only twin `hkl_search_select` keeps **only the selected reflection** (reservoir draw). The per-thread stack array drops from `T[1024]` to `T[1]`, 172 kB → 168 B. |
| FUNNEL | not ported | compiles (`-DFUNNEL`); untested |
| NCrystal | not needed | **needed at link time**: `main`'s Single_crystal now `%include`s `mccode-ncrystal-lib` (`pip install ncrystal`) |

## A: the fixes

1. `hkl_search`: `int i, j = 0;` (`j` was uninitialized).
2. CPU `SPLIT` ki-reuse cache disabled (`if (0 && order == 1 && …)`). The selection now happens
   inside `hkl_search`, so a cache hit left a stale reflection index.
3. Reservoir guard: `if (sel < 0 || rand0max(total) < refl)`. Without it, `rand01()==1.0` left
   no selection and picked `L[0]`.
4. Monitor flat indices made row-major, to match `create_darr2d(nx,ny)`: PSD `i*ny+j`,
   Divergence `i*nv+j`, TOFLambda `j*nL+i`, DivLambda `i*nh+j`. Before this, every 2D sample
   monitor came out transposed.

## B: what `make_omp.py` does (prototype of design PRs 1–5)

- Adds the macro block (`OMPTARGET` → `MCGPU`, `<omp.h>`, `requires unified_shared_memory`).
- Renames the 61 device-build guards `#ifdef/#ifndef OPENACC` to `MCGPU`. The single guard
  around `acc_attach` and the `openacc.h`/`accelmath.h` includes stay OpenACC-only.
- Adds stacked OpenMP twins: 30 `omp atomic*`, 100 `omp declare target(...)`, 89/88
  `omp target update to/from`, 7 `omp target teams loop` (raytrace_all, funnel,
  `sort_absorb_last`). `acc routine`, `loop seq`, `loop independent` and `shape` get no twin.
- Moves `declare target(_instrument_var)` before `instrument = &_instrument_var` (clang warned
  that it came after first use).
- Single_crystal as in the table above. **Numerical change on the device only**, and it applies
  to `-DOPENACC` as well: one extra random number per reachable reflection.

## Verified here (macOS arm64, clang 21.1.8 + libomp from mccode-dev)

- A, B-CPU, B `-DOMPTARGET` (host fallback) and B `-DOMPTARGET -DFUNNEL` all **compile and link**.
  The only warnings left were already there (`sprintf` redefinition, `par6`).
- B with no defines: **preprocessed output identical to stock main** apart from `__FILE__`
  strings (`clang -E`).
- B `-DOPENACC`: preprocessed output identical to stock main **apart from the intended
  Single_crystal change** (stub `openacc.h`).
- `compare.py`: self-test passes; zero flags on identical data; flags an artificially transposed
  PSD file.
- No GPU, no nvc, no CCE here. See the local runs below.

## Local runs (host-fallback OpenMP, 1e8 rays, seed 1234)

Test parameters, chosen to open the beam (the defaults give about 20 rays at the sample per 1e7):
`Slit2_width=0.01 Slit2_height=0.01 PinholeCollimator_width=0.01 PinholeCollimator_height=0.01 SPLITS=20`.
A needs **all** parameters given explicitly and no `-y` (`A_04_fixed/params.txt`). Its June
runtime makes `-y` overwrite every parameter with its default, even ones given on the command
line. `main` later changed `-y` to fill in only parameters that were not given.

| `compare.py ref_cpu <run>` | Upstream of crystal (PSD, 2×Div, TOFL, DivL) | After crystal (Structure + 3 event lists) | Flags |
|---|---|---|---|
| B `-DOMPTARGET` | **bit-identical** (χ² = 0) | z = +0.39, +0.18, −0.84, +0.39; χ²/dof 0.93 | 0 |
| A (fixed) | statistical: \|z\| ≤ 1.04, χ²/dof 0.86–1.00 (June components and seeding) | \|z\| ≤ 0.71; χ²/dof 0.95 | 0 |
| Joachim's 04, unfixed (control) | the same, **except `At_SampleOverviewDIVVDIVH.pos`: χ²/dof 2.08, against its transpose 0.91** | \|z\| ≤ 0.92 | 1 (transposed) |

The control shows fix 4 is real. At this statistics level the other three monitors are too
close to symmetric for the transpose to show, but the code bug is the same.

The host fallback runs a `target teams` region as a single team, so wall time equals the serial
CPU time (about 250 s). These runs check **semantics only**: the pragmas, the `declare target`
set, and the Single_crystal reservoir selection. They say nothing about speed. Device memory
(USM or maps) is never exercised on the host. For A, that is what the LUMI run is for.

## On LUMI

```bash
module load PrgEnv-cray craype-accel-amd-gfx90a rocm      # plus a python with: pip install ncrystal numpy
./build.sh cce                                            # builds A, B and B2; or: ./build.sh amdclang
./build.sh cpu                                            # CPU reference, stock main
```
Do not run `nmx_omp` (B) here.

Run from each variant's own directory, because `Rubredoxin.lau` is looked up in the working directory:
```bash
export OMP_TARGET_OFFLOAD=MANDATORY     # fail instead of silently running on the host
export CRAY_ACC_DEBUG=1                 # CCE: show kernel launches/transfers (LIBOMPTARGET_INFO=-1 for amdclang)
P=$(cat A_04_fixed/params.txt)          # all 32 params, wide-open slits, SPLITS=20
(cd B2_main_maps && ./nmx_maps -n 1e8 -s 1234 -d omp_gpu $P | tee run.log)
python3 compare.py B_main_usm/ref_cpu B2_main_maps/omp_gpu
(cd A_04_fixed && ./nmx_A -n 1e8 -s 1234 -d omp_A_gpu $P)   # no -y for A (see above)
python3 compare.py B_main_usm/ref_cpu A_04_fixed/omp_A_gpu
```
`B_main_usm/ref_cpu` is already here (1e8 rays, macOS, stock main), so `./build.sh cpu` and a new
reference are optional. Compare wall times with `time`.

### What each outcome tells us

| Result | Meaning |
|---|---|
| B2 runs, `compare.py` shows 0 flags | Current `main` runs NMX on LUMI without USM, flattening or mappers. |
| B2 stops with `[mcmap] FATAL` | The message names the component and array, or the missing device. Send me the line. |
| B2 passes the readback, then crashes or hangs | Probably in the kernel: stack, or a compiler issue. Try `--vecsize=64`, and send the output of `CRAY_ACC_DEBUG=1`. |
| B2 is slow | Tune `--numgangs` / `--vecsize` first. With amdclang, `-munsafe-fp-atomics` gives hardware double atomics; not on by default because it is untested here. |
| A runs, `compare.py` shows 0 flags | Fixes hold on the GPU; the explicit-map route is validated on LUMI for NMX. |
| A or B2 flagged against `ref_cpu` | A real CPU/GPU difference. Tell me which monitor; the first flagged one in beam order is the place to look. |
| A is much slower than B2 | Expected if the compiler gives A one thread per team: A's kernel is `target teams` + `loop`. Not verified. |
| A crashes or hangs | Most likely a map that is missing or wrong. `CRAY_ACC_DEBUG` output shows which transfer. |
| B fails to compile on CCE | Compiler issue with the OpenMP lines from `main`. Note the version and the line; `make_omp.py` is easy to adjust. |

Where USM exists (`./build.sh nvc` on an NVIDIA machine with HMM), B can be run the same way,
with `-y` allowed. That checks the `main`-based OpenMP lines on a real GPU, including
non-flattened structs under USM. It says nothing about LUMI's memory limits.

`compare.py` compares statistically: totals by z-score, bins by χ²/dof, and it detects
transposed 2D monitors. The same seed is **not** expected to reproduce numbers: the device
Single_crystal uses the RNG differently, and A was built from June components. Keep `-n`,
`-s` and the MPI rank count identical (none used here).
