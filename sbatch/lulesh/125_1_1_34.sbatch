#!/bin/bash
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --output=/home/nfs/kona/pwr2018/output/lulesh/125_1_1_34/lu.out

source /home/nfs/kona/pwr2018/config/lulesh/125_1_1_34.config
source /home/nfs/kona/pwr2018/pwrlib-install/script/hwloc_msr_profile
export LD_PRELOAD=/home/nfs/kona/pwr2018/profiler.so
srun -N 1 -n 1 /home/nfs/kona/benchmarks/lulesh2.0.3/lulesh2.0 -s 34
