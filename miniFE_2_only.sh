#!/bin/bash
HOME_PATH=/home/kona
export LD_LIBRARY_PATH=$HOME_PATH/libmsr/build/libmsr/lib:$HOME_PATH/pwr2018/pwrlib-install/lib
modprobe msr
source $HOME_PATH/pwr2018/pwrlib-install/script/hwloc_msr_profile
BENCHMARK_PATH=$HOME_PATH/miniFE/src/miniFE.x
ORIG_OUTPUT_PATH=$HOME_PATH/pwr2018/output_miniFE/miniFE/proc1
export PROFILER_FREQUENCY=100000000

for powercap in 9.5 10 10.5 11 11.5 12 12.5 13 13.5 14 14.5 15
do
	OUTPUT_PATH=$ORIG_OUTPUT_PATH	
	$HOME_PATH/pwr2018/src/powercap $powercap
	OUTPUT_PATH=$OUTPUT_PATH/cap_${powercap/./-}

	mkdir -p $OUTPUT_PATH
	
	mkdir $OUTPUT_PATH/noprofiler-$count
	mkdir $OUTPUT_PATH/nowrapper-$count
	mkdir $OUTPUT_PATH/profiler-$count

	echo -n > $OUTPUT_PATH/noprofiler-$count/output.dat
	echo -n > $OUTPUT_PATH/nowrapper-$count/output.dat
	echo -n > $OUTPUT_PATH/profiler-$count/output.dat

	echo -n > $OUTPUT_PATH/noprofiler-$count/time.dat
	echo -n > $OUTPUT_PATH/nowrapper-$count/time.dat
	echo -n > $OUTPUT_PATH/profiler-$count/time.dat

	echo "proc=1 size=256x3 freq=100ms powercap=$powercap" > $OUTPUT_PATH/config.dat
	
	(time mpirun --allow-run-as-root -n 1 $BENCHMARK_PATH -nx 256 -ny 256 -nz 256) > $OUTPUT_PATH/noprofiler-$count/output.dat 2> $OUTPUT_PATH/noprofiler-$count/time.dat
	
	export PROFILER_OUTPUT_PATH=$OUTPUT_PATH/nowrapper
	export PROFILER_OUTPUT_SUFFIX=-$count
	export LD_PRELOAD=$HOME_PATH/pwr2018/src/profiler_nowrapper.so
	(time mpirun --allow-run-as-root -n 1 $BENCHMARK_PATH -nx 256 -ny 256 -nz 256) > $OUTPUT_PATH/nowrapper-$count/output.dat 2> $OUTPUT_PATH/nowrapper-$count/time.dat


	export PROFILER_OUTPUT_PATH=$OUTPUT_PATH/profiler
	export PROFILER_OUTPUT_SUFFIX=-$count
	export LD_PRELOAD=$HOME_PATH/pwr2018/src/profiler.so 
	(time mpirun --allow-run-as-root -n 1 $BENCHMARK_PATH -nx 256 -ny 256 -nz 256) > $OUTPUT_PATH/profiler-$count/output.dat 2> $OUTPUT_PATH/profiler-$count/time.dat

done


