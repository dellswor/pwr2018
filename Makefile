CC = mpicc
PROFILER_PATH = /home/kona/pwr2018
LIBPWR_PATH = /home/kona/pwr2018/pwrlib-install

all: helloworld profiler
clean:
	rm *.o *.so *.dat
helloworld: helloworld.c
	$(CC) helloworld.c -L$(PROFILER_PATH) -o hello.o
profiler: profiler.c
	$(CC) -fPIC -shared -o profiler.so profiler.c -lpthread -I$(LIBPWR_PATH)/include -L$(LIBPWR_PATH)/lib -lpwr
