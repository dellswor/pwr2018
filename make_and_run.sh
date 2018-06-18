#!/bin/bash

make clean
make all
source /home/kona/research2018/pwrGIT/script/hwloc_profile
LD_PRELOAD=/home/kona/research2018/mpiHello/profiler.so $1 $2 $3 $4
