#!/bin/bash
#SBATCH --time=10:00:00
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4
#SBATCH --output=/home/nfs/kona/pwr2018/output/lulesh/135_2_8_1/lu.out

source /home/nfs/kona/pwr2018/config/lulesh/135_2_8_1.config
source /home/nfs/kona/pwr2018/pwrlib-install/script/hwloc_msr_profile
export LD_PRELOAD=/home/nfs/kona/pwr2018/profiler.so
srun -N 2 -n 8 /home/nfs/kona/benchmarks/lulesh2.0.3/lulesh2.0 -s 1
