#!/bin/bash
# Build the EPICURE NMX test variants.   usage: ./build.sh <toolchain> [extra cflags, e.g. -DFUNNEL]
#   cpu       stock-main CPU reference (cc)              -> B_main_usm/nmx_main_cpu
#   cce       LUMI, Cray CCE, OpenMP offload to MI250X    -> A_04_fixed/nmx_A, B_main_usm/nmx_omp, B2_main_maps/nmx_maps
#   amdclang  LUMI, ROCm amdclang                         -> same
#   nvc       NVIDIA HPC SDK                              -> same (+ B_main_usm/nmx_acc, OpenACC)
# Needs ncrystal-config on PATH for B (main's Single_crystal links NCrystal): pip install ncrystal
set -euo pipefail
cd "$(dirname "$0")"
tc=${1:?toolchain: cpu|cce|amdclang|nvc}; shift
X="-O2 -DMCSX_REFL_SLIST_SIZE=1024 $*"
NC=$(ncrystal-config --show buildflags)

case $tc in
  cpu)      cc $X -o B_main_usm/nmx_main_cpu B_main_usm/NMX_simplified_main.c $NC -lm; exit ;;
  cce)      CC="cc";       OMP="-fopenmp" ;;                         # module load PrgEnv-cray craype-accel-amd-gfx90a rocm
  amdclang) CC="amdclang"; OMP="-fopenmp --offload-arch=gfx90a" ;;
  nvc)      CC="nvc";      OMP="-mp=gpu -gpu=mem:unified -Minfo=mp"
            nvc $X -fast -acc=gpu -gpu=mem:managed -Minfo=accel -DOPENACC -o B_main_usm/nmx_acc B_main_usm/NMX_simplified_omp.c $NC -lm ;;
  *) echo "unknown toolchain $tc" >&2; exit 1 ;;
esac
# B2: main + make_omp.py + make_omp_maps.py. -DOMPTARGET, no USM: this is the one to run on LUMI.
OMP2=${OMP/ -gpu=mem:unified/}
$CC $X $OMP2 -DOMPTARGET -DNOSIGNALS -o B2_main_maps/nmx_maps B2_main_maps/NMX_simplified_omp_maps.c $NC -lm
# A: Joachim's 04 + fixes. Switches on _OPENMP, explicit deep maps, no NCrystal.
$CC $X $OMP -DNOSIGNALS -o A_04_fixed/nmx_A A_04_fixed/NMX_simplified.c -lm
# B: main + make_omp.py. -DOMPTARGET, unified shared memory, no deep maps.
# Compile check only on LUMI: no HSA_XNACK there, so nmx_omp cannot run.
$CC $X $OMP -DOMPTARGET -o B_main_usm/nmx_omp B_main_usm/NMX_simplified_omp.c $NC -lm
ls -l A_04_fixed/nmx_A B_main_usm/nmx_* B2_main_maps/nmx_maps
