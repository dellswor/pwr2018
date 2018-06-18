#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int logfd;
FILE *logfile=NULL;

int start_write(char *fname)
{
  logfd=open(fname,O_WRONLY|O_CREAT|O_NDELAY, S_IRUSR|S_IWUSR);
  if(logfd<0)
    {
	printf("failed to get file descriptor: %i, errno: %i\n",logfd,errno);
	return 1;	
}
  logfile = fdopen(logfd, "w");
  if(logfile==NULL)
    {
printf("failed to open erno is %i\n",errno);
return 2;
}
  return 0;
}
int write_data(char *data)
{
  //printf("%p\n",logfile);
  //printf("%p\n",data);
  //fflush(stdout);
  fprintf(logfile,"%s", data);
  //printf("wrote: %s",data);
  return 0;
}
int end_write()
{
  fclose(logfile);
  close(logfd);
}
