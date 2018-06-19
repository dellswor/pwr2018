CC = mpicc
LIBPWR_PATH = /home/kona/pwr2018/pwrlib-install

all: profiler
clean:
	rm *.o *.so *.dat
profiler: profiler.c
	$(CC) -fPIC -shared -o profiler.so profiler.c -lpthread -I$(LIBPWR_PATH)/include -L$(LIBPWR_PATH)/lib -lpwr
