CC = mpicc
PROFILER_PATH = /home/kona/research2018/mpiHello
LIBPWR_PATH = /home/kona/research2018/pwrGIT/lib
all: helloworld profiler
clean:
	rm *.o *.so *.dat
helloworld: helloworld.c
	$(CC) helloworld.c -L$(PROFILER_PATH) -o hello.o
profiler: profiler.c
	$(CC) -fPIC -shared -o profiler.so profiler.c -lpthread $(LIBPWR_PATH)/libpwr.so
