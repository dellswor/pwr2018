# pwr2018
Tools for the 2018 power work

### Dependencies
* LIBMSR https://github.com/LLNL/libmsr/
* PowerAPI https://github.com/pwrapi/pwrapi-ref
* MPI

### Kernel Req.
* MSR-SAFE

### Instruction
* link LIBMSR and PowerAPI and MPI against this
> source /$(PATH_TO_PWRLIB)/script/hwloc_msr_profile

> export LD_PRELOAD=/$(PATH_TO_PROFILER)/profiler.so

> srun *commands*
