CC = mpicc
LIBPWR_PATH =/home/kona/pwr2018/pwrlib-install
LIBMSR_PATH = /home/kona/libmsr/build/libmsr
PROFILER_PATH ?= .
all: profiler profiler_nowrapper powercap
profiler: profiler.c
	$(CC) -DWRAPPER_TOG=1 -Wall -g -fPIC -shared -o $(PROFILER_PATH)/profiler.so profiler.c -lpthread -I$(LIBPWR_PATH)/include -L$(LIBPWR_PATH)/lib -I$(LIBMSR_PATH)/include -L$(LIBMSR_PATH)/lib -lpwr -lmsr
profiler_nowrapper: profiler.c
	$(CC) -DWRAPPER_TOG=0 -Wall -g -fPIC -shared -o $(PROFILER_PATH)/profiler_nowrapper.so profiler.c -lpthread -I$(LIBPWR_PATH)/include -L$(LIBPWR_PATH)/lib -I$(LIBMSR_PATH)/include -L$(LIBMSR_PATH)/lib -lpwr -lmsr
powercap: powercap.c
	gcc -Wall -g -o $(PROFILER_PATH)/powercap powercap.c -I$(LIBPWR_PATH)/include -L$(LIBPWR_PATH)/lib -lpwr
