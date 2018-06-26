#! /bin/bash
#SBATCH --time=0:05:00
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=16
#SBATCH --output=lu_prof.out

source /home/nfs/kona/pwr2018/pwrlib-install/script/hwloc_msr_profile
export LD_PRELOAD=/home/nfs/kona/pwr2018/profiler.so
srun -N 2 -n 32 /home/nfs/kona/pwr2018/test-apps/hello.o
