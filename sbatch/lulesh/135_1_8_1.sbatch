#!/bin/bash
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=8
#SBATCH --output=/home/nfs/kona/pwr2018/output/lulesh/135_1_8_1/lu.out

source /home/nfs/kona/pwr2018/config/lulesh/135_1_8_1.config
source /home/nfs/kona/pwr2018/pwrlib-install/script/hwloc_msr_profile
export LD_PRELOAD=/home/nfs/kona/pwr2018/profiler.so
srun -N 1 -n 8 /home/nfs/kona/benchmarks/lulesh2.0.3/lulesh2.0 -s 1
