#!/bin/sh
LIBMSR_PATH=/path/to/libmsr
LIBPWR_PATH=/path/to/pwrapi
PROFILER_PATH=/path/to/profiler
export LD_LIBRARY_PATH=$LIBMSR_PATH/lib:$LIBPWR_PATH/lib
modprobe msr
source $LIBPWR_PATH/script/hwloc_msr_profile
BENCHMARK_PATH=/path/to/benchmark
BENCHMARK_PARAM="argument to benchmark"
ORIG_OUTPUT_PATH=$PROFILER_PATH/output_miniFE/
export PROFILER_FREQUENCY=100000000
proc=2
for powercap in 9.5 10 10.5 11 11.5 12 12.5 13 13.5 14 14.5 15
do
	OUTPUT_PATH=$ORIG_OUTPUT_PATH	
	$PROFILER_PATH/src/powercap $powercap
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
	
	echo "$BENCHMARK_PARAM proc=$proc freq=100ms powercap=$powercap" > $OUTPUT_PATH/config.dat
	
	(time mpirun --allow-run-as-root -n $proc $BENCHMARK_PATH $BENCHMARK_PARAM) > $OUTPUT_PATH/noprofiler-$count/output.dat 2> $OUTPUT_PATH/noprofiler-$count/time.dat
	
	export PROFILER_OUTPUT_PATH=$OUTPUT_PATH/nowrapper
	export PROFILER_OUTPUT_SUFFIX=-$count
	export LD_PRELOAD=$PROFILER_PATH/src/profiler_nowrapper.so
	(time mpirun --allow-run-as-root -n $proc $BENCHMARK_PATH $BENCHMARK_PARAM) > $OUTPUT_PATH/nowrapper-$count/output.dat 2> $OUTPUT_PATH/nowrapper-$count/time.dat


	export PROFILER_OUTPUT_PATH=$OUTPUT_PATH/profiler
	export PROFILER_OUTPUT_SUFFIX=-$count
	export LD_PRELOAD=$PROFILER_PATH/src/profiler.so 
	(time mpirun --allow-run-as-root -n $proc $BENCHMARK_PATH $BENCHMARK_PARAM) > $OUTPUT_PATH/profiler-$count/output.dat 2> $OUTPUT_PATH/profiler-$count/time.dat

done


