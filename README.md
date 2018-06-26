# pwr2018
Tools for the 2018 power work

Dependencies:

-LIBMSR
-PowerAPI
-MPI

Kernel Req.: MSR-SAFE

source /$(PATH_TO_PWRLIB)/script/hwloc_rapl_profile

LD_PRELOAD=/$(PATH_TO_PROFILER)/profiler.so mpirun --allow-run-as-root *commands*
