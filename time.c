#include <time.h>

#define MAX_NANO 999999999

struct timespec t;
int count=1;
unsigned long init_time;
unsigned long interval;

unsigned long ms_now()
{
	unsigned long currms;
	clock_gettime(CLOCK_MONOTONIC, &t);
	currms = t.tv_sec*1000+t.tv_nsec/1000000;
	return currms;
}
unsigned long ns_now()
{
	unsigned long currns;
	clock_gettime(CLOCK_MONOTONIC, &t);
	currns = t.tv_sec*1000000000+t.tv_nsec;
	return currns;
}
int timer_init(unsigned long ns)
{
	init_time = ns_now();
	interval = ns;
}
int timer_sleep()
{
	if(count==1)
	{
		init_time=ns_now();
	}
	clock_gettime(CLOCK_MONOTONIC, &t);
	if(t.tv_nsec+ns <= MAX_NANO)
	{
		t.tv_nsec+=interval;
	}
	else
	{
		t.tv_sec+=1;
		t.tv_nsec+=interval-MAX_NANO;
	}
	t.tv_nsec -= ns_now() - interval*count+init_time;
	count++;
	return clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t, NULL);
}
