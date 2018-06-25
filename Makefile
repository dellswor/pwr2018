CC = mpicc
LIBPWR_PATH =/home/nfs/kona/pwr2018/pwrlib-install
LIBMSR_PATH = /home/nfs/kona/libmsr/build/libmsr
all: profiler
clean:
	rm *.o *.so *.dat
profiler: profiler.c
	$(CC) -fPIC -shared -o profiler.so profiler.c -lpthread -I$(LIBPWR_PATH)/include -L$(LIBPWR_PATH)/lib -I$(LIBMSR_PATH)/include -L$(LIBMSR_PATH)/lib -lpwr -lmsr
