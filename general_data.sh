#!/bin/sh
LIBMSR_PATH=$1
LIBPWR_PATH=$2
PROFILER_PATH=$3
export LD_LIBRARY_PATH=$LIBMSR_PATH/lib:$LIBPWR_PATH/lib
modprobe msr
source $LIBPWR_PATH/script/hwloc_msr_profile
BENCHMARK_PATH=$6
BENCHMARK_PARAM=$7
ORIG_OUTPUT_PATH=$4
export PROFILER_FREQUENCY=100000000
RUN_OPTIONS=$5
for powercap in 9.5 10 10.5 11 11.5 12 12.5 13 13.5 14 14.5 15
do
$PROFILER_PATH/src/powercap $powercap
OUTPUT_PATH=$ORIG_OUTPUT_PATH
OUTPUT_PATH=$OUTPUT_PATH/cap_${powercap/./-}
mkdir -p $OUTPUT_PATH
for count in 1 2 3 4 5
do
	mkdir $OUTPUT_PATH/noprofiler-$count
	mkdir $OUTPUT_PATH/nowrapper-$count
	mkdir $OUTPUT_PATH/profiler-$count

	echo -n > $OUTPUT_PATH/noprofiler-$count/output.dat

	echo -n > $OUTPUT_PATH/nowrapper-$count/output.dat
	echo -n > $OUTPUT_PATH/profiler-$count/output.dat

	echo -n > $OUTPUT_PATH/noprofiler-$count/time.dat
	echo -n > $OUTPUT_PATH/nowrapper-$count/time.dat
	echo -n > $OUTPUT_PATH/profiler-$count/time.dat
	
	echo "$BENCHMARK_PARAM $RUN_OPTIONS freq=100ms powercap=$powercap" > $OUTPUT_PATH/config.dat
	echo $powercap $count "noprofiler"
	(time mpirun $RUN_OPTIONS $BENCHMARK_PATH $BENCHMARK_PARAM) > $OUTPUT_PATH/noprofiler-$count/output.dat 2> $OUTPUT_PATH/noprofiler-$count/time.dat

	export PROFILER_OUTPUT_PATH=$OUTPUT_PATH/nowrapper
	export PROFILER_OUTPUT_SUFFIX=-$count
	export LD_PRELOAD=$PROFILER_PATH/src/profiler_nowrapper.so
	echo $powercap $count "nowrapper"
	(time mpirun $RUN_OPTIONS $BENCHMARK_PATH $BENCHMARK_PARAM) > $OUTPUT_PATH/nowrapper-$count/output.dat 2> $OUTPUT_PATH/nowrapper-$count/time.dat


	export PROFILER_OUTPUT_PATH=$OUTPUT_PATH/profiler
	export PROFILER_OUTPUT_SUFFIX=-$count
	export LD_PRELOAD=$PROFILER_PATH/src/profiler.so 
	echo $powercap $count "profiler"
	(time mpirun $RUN_OPTIONS $BENCHMARK_PATH $BENCHMARK_PARAM) > $OUTPUT_PATH/profiler-$count/output.dat 2> $OUTPUT_PATH/profiler-$count/time.dat
done
done


