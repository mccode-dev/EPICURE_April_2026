# EPICURE: McStas GPU port, summary of the work so far

Status as of 2026-11-04. Sources:
- [mccode-dev/EPICURE_April_2026](https://github.com/mccode-dev/EPICURE_April_2026), branches `main`, `Minimal-hacking`, `03_NMX_omp`, `02_work_joachim`, `04_work_joachim`
- McCode branches [`EPICURE_mini_hackathon`](https://github.com/mccode-dev/McCode/tree/EPICURE_mini_hackathon) and [`EPICURE_pwhacks`](https://github.com/mccode-dev/McCode/tree/EPICURE_pwhacks). Both branch off `main` at `ed9bf573c` (2026-05-23).

## Goal

Run McStas instruments, and NMX in particular, on non-NVIDIA GPUs (AMD on LUMI/Cray). Today's
GPU path is OpenACC with `nvc`, which only targets NVIDIA. The chosen route is **OpenMP 5
target offload**. The Makefiles in the repo use `cc -fopenmp` (Cray CCE) and `rocprofv3`, so
the hardware is AMD.

## Timeline

| When | Where | Who | What |
|---|---|---|---|
| Apr 9–14 | McCode `EPICURE_cogen_flatten_structs`, then `EPICURE_mini_hackathon` | PW | Code generator: merged the `_comp->_parameters` sub-struct into the component struct, flattened the instrument struct, dropped `num_gangs`/`vector_length`, added an experimental `_instrument_var._counter`. Example 01_Minimal_v2 then ran with OpenACC **without** `-gpu=managed`, using local components with fixed-size static arrays. |
| May 26 | EPICURE `main` | JS | `translate-table.md`: a 1:1 OpenACC → OpenMP pragma mapping. First declare-target work. |
| May 26 – Jun 4 | McCode `EPICURE_pwhacks` | PW | OpenMP prototype of the code generator. It **replaces** `acc` pragmas with `omp` ones; it does not add them alongside. Adds `defined(OPENACC) \|\| defined(_OPENMP)` guards in about 54 component and library files, `omp atomic` in the monitors, and `target data map` regions around `raytrace_all` and `raytrace_all_funnel` with a hard-coded `num_teams(64) thread_limit(16)`. |
| May 28 | EPICURE `main`, 01_Minimal v4/v5 | PW+JS | First working OpenMP GPU run: "This actually works with `nvc -mp=gpu … -DNOSIGNALS -DFUNNEL`". Monitor atomics, an example dataset. `declare mapper` was tried and **commented out because nvc does not handle it**. |
| Jun 4 | EPICURE `main` | PW | Regenerated 02/03/04 with the pwhacks code generator. Local hacked components were folded back into McCode. |
| Jun 10–15 | `Minimal-hacking`, `03_NMX_omp` | JS/PW | Cray CCE build, `declare target link`, less data transfer in the funnel path. Branch head is "Some racy progress". |
| Jun 17 – Oct 23 | `02_work_joachim` (templateNMX: source, slit, `SPLIT` Single_crystal, PSD_monitor_4PI) | JS | Single_crystal tuned for the GPU: `tau_data` shrunk to fit L1, quantities recomputed instead of stored, the per-particle `MCSX_REFL_SLIST_SIZE` list removed, and in the end a **single-pass Monte Carlo selection inside `hkl_search`**. Also a FUNNEL path with explicit deep maps. One attempt to cut `-O0` stack use was reverted. |
| Sep 14 – Oct 23 | `04_work_joachim` (full NMX_simplified, 87 components) | JS | The 02 approach applied to the full instrument, non-FUNNEL path only. See `02_NMX_simplified_status.md`. |

## What has been shown to work

- **OpenMP target offload of the McStas raytrace loop works**, on nvc `-mp=gpu` and, judging by
  the Makefiles, Cray CCE. That covers Minimal, templateNMX and NMX_simplified.
- **Functions need no annotation.** All `#pragma acc routine` became redundant. OpenMP ≥ 5.0
  implicitly declares a function as target code when it is called from a target region in the
  same translation unit, and McCode always generates exactly one translation unit. The many
  leftover `#pragma acc` lines in the OpenMP builds were silently ignored.
- **Globals need `declare target`.** This covers runtime globals (`mcseed`, `mcgravitation`,
  `mcdotrace`, `mcncount`) and the component and instrument instance variables
  (`declare target link(...)`).
- **Explicit deep copies work for the data that matters**: monitor arrays mapped as `arr[0][0:nx*ny]`
  with flat indexing on the device, `hkl_list[0:count]` and `Mon2D_Buffer[0:dim]`. Every case was
  written by hand per instrument.
- **The algorithm change with the biggest effect** is in Single_crystal: select the reflection
  during the search instead of storing a tau list. Today's `main` puts
  `struct tau_data T[MCSX_REFL_SLIST_SIZE]` (168 B per entry) **on each GPU thread's stack**.
  NMX's `-DMCSX_REFL_SLIST_SIZE=1024` makes that about 172 kB per thread. That is a problem
  for OpenACC too.

## Tried and dropped (don't repeat)

| Idea | Outcome |
|---|---|
| `#pragma omp declare mapper` for nested pointers | Did not work with nvc (commit `d27d752`). Explicit `map(s.p[0][0:n])` was used instead. |
| `num_teams(64) thread_limit(16)` hard-coded in the code generator | Removed by JS in 02/04: plain `target teams` + `loop`. 1024 threads is far too few for a GPU. |
| Nested `omp target teams loop` on the `SPLIT` loop inside `raytrace()` | Removed in 04. You cannot open a target region inside device code. |
| Struct flattening (`_parameters` merge) | Needed for the OpenACC no-managed-memory experiment. **Not needed for OpenMP**: an inline nested struct is mapped by value together with its parent. |
| `_counter` and `weights` debug sums | Instrumentation only. Drop it. |
| Reducing `-O0` stack use in the funnel path | Reverted (`2b7740e`). |

## Where the code stands

- **Nothing is upstream.** The McCode branches stop at 2026-06-04. `main` has had about 53
  commits to the code generator and runtime since then, including RNG seed decorrelation
  (#2807), unique `_uid` across batches and ranks, `randstate` sizing, FUNNEL guards, and an
  atomic-capture fix for Monitor_nD list mode. Rebasing `EPICURE_pwhacks` would mean conflicts
  plus re-deciding the design choices it got wrong (below). **Start fresh from `main`**, as
  `03_OpenMP_design.md` proposes.
- `EPICURE_pwhacks` design problems that must not be carried over:
  1. It switches on `_OPENMP`, which **any** `-fopenmp` build defines, including host-only
     OpenMP. Use a McCode-owned macro instead.
  2. It replaces OpenACC instead of adding OpenMP next to it. The OpenACC path breaks.
  3. `mccode-r.h.in`: `#elif defined(_OPENMP) / #include <omp.h>` sits *inside*
     `#ifndef GCCOFFLOAD` under `#if defined(OPENACC)`, so an OpenMP-only build never includes `<omp.h>`.
  4. The hard-coded `num_teams(64) thread_limit(16)`.
  5. It disables the CPU `FUNNEL` guard by commenting it out.
- The EPICURE generated `.c` files are hand-edited generated code (forbidden by AGENTS.md
  rule 1). They are useful as a **specification** of what the code generator, components and
  runtime must produce, not as code to merge.

## Results since this review

- **LUMI has no `HSA_XNACK=1`**, so unified shared memory is not an option there. Explicit deep
  maps are required, which makes `04_work_joachim` the reference for that work. The design doc
  has been changed accordingly.
- Three hand-made test files exist in `lumi_test/`:
  - **B2**, current `main` with explicit, checked transfers (`omp_target_alloc`, device addresses in
    new struct members) and no USM, flattening or mappers. Built to run on LUMI. Host-pointer-poisoned
    host runs agree with stock `main`; it has not yet run on a GPU.
  - **A**, 04 with four output-changing bugs fixed. Also runs on LUMI.
  - **B**, current `main` plus OpenMP on unified memory. It cannot run on LUMI. It does show
    that the OpenMP lines generated from `main` work on the host: monitors before the crystal
    are bit-identical to stock `main`, and those after it agree statistically.
- A also agrees statistically with stock `main` on host fallback. Nothing has been run on a GPU
  yet in this review.

## Open questions for JS

1. Which compiler, version and flags, and which hardware, give the "good state" of 04 (CCE on
   MI250X? nvc on A100/H100?)
2. Do numbers exist for 04 against the CPU reference (wall time, monitor agreement)? Nothing is
   committed to the repo.
3. Was the reservoir selection in `hkl_search` checked statistically against the original
   two-pass selection?
