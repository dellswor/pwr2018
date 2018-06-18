#include <time.h>

#define MAX_NANO 999999999

struct timespec t;
unsigned long ms_now()
{
  unsigned long currms;
  clock_gettime(CLOCK_MONOTONIC, &t);
  currms = t.tv_sec*1000+t.tv_nsec/1000000;
  return currms;
}
int sleep_abs(int ns)
{
  clock_gettime(CLOCK_MONOTONIC, &t);
  if(t.tv_nsec+ns <= MAX_NANO)
  t.tv_nsec+=ns;
  else
  {
    t.tv_sec+=1;
    t.tv_nsec+=ns-MAX_NANO;
  }
  return clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t, NULL);
}
