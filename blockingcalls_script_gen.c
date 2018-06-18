#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

  void removeSubstr(char *s,const char *toremove)
  {
    while( s=strstr(s,toremove) )
      memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));
  }

int main()
{
  FILE *file;
  char *buffer = (char *)malloc(10000 * sizeof(char));
  file = fopen("blockingcalls_list.txt", "r");
  if(file==NULL)
    printf("failed to open erno is %i\n",errno);
  int counter=0;
  char c;
  while(c != EOF)
  {
    c = (char)fgetc(file);
    buffer[counter] = c;
    counter++;
  }
  buffer[counter]='\0';
  char **functions = (char **)malloc(100 * sizeof(char *));
  int funccount =0;
  int funccount2 =0;
  functions[funccount] = (char *)malloc(500 * sizeof(char));

  for(int i=0; i<counter; i++)
  {

    functions[funccount][funccount2] = buffer[i];


    funccount2++;

    if(buffer[i]==')')
    {
      functions[funccount][funccount2]='\0';
      funccount++;
      functions[funccount] = (char *)malloc(500 * sizeof(char));
      funccount2=0;
    }
  }
  fclose(file);
  free(buffer);

  file = fopen("blocking_wrappers.c", "w");
  for(int i=0; i<funccount; i++)
  {
    while(*functions[i]!='i')
    {
      *functions[i]++;
    }

    char *func = (char *)malloc(500 * sizeof(char));
    char *funcname = (char *)malloc(100 * sizeof(char));

    funccount2 = 0;
    while(functions[i][funccount2]!='\0')
    {
      func[funccount2] = functions[i][funccount2];
      funccount2++;
    }
    func[funccount2] = '\0';
    while(*func!='t')
    {
      *func++;
    }
    *func++;
    *func++;

    funccount2 = 0;
    while(func[funccount2]!='(')
    {
      funcname[funccount2] = func[funccount2];
      funccount2++;
    }
    funcname[funccount2]='\0';

    char *realfunc = (char *)malloc(500 * sizeof(char));
    int realfunccount=0;
    while(func[realfunccount]!='(')
    {
      realfunccount++;

    }
    int asdf = 0;
    while(func[realfunccount]!='\0')
    {
      realfunc[asdf]=func[realfunccount];
      asdf++;
      realfunccount++;
    }
    realfunc[asdf]='\0';

    //realfunc=&realfunc[realfunccount];
    removeSubstr(realfunc, "int");
    removeSubstr(realfunc, "const");
    removeSubstr(realfunc, "void");
    removeSubstr(realfunc, "*");
    removeSubstr(realfunc, "MPI_Datatype");
    removeSubstr(realfunc, "MPI_Comm");
    removeSubstr(realfunc, "[]");
    removeSubstr(realfunc, "MPI_Win");
    removeSubstr(realfunc, "MPI_Status");
    removeSubstr(realfunc, "MPI_Request");
    removeSubstr(realfunc, "MPI_File");
    removeSubstr(realfunc, "MPI_Message");
    removeSubstr(realfunc, "MPI_A");
    removeSubstr(realfunc, "MPI_Op");
    removeSubstr(realfunc, "MPI_Offset");
    removeSubstr(realfunc, "MPI_Info");
printf("realfunc %s\n",realfunc);
    char *function = (char *)malloc(5000 * sizeof(char));
    sprintf(function, "%s{\
      char wrapper_buffer[1000];\
      sprintf(wrapper_buffer,\"%s start, %%lu ms\\n\",ms_now());\
      write_data(wrapper_buffer);\
      int wrapper_return = P%s%s;\
      sprintf(wrapper_buffer,\"%s end, %%lu ms\\n\",ms_now());\
      write_data(wrapper_buffer);\
      return wrapper_return;\
    }",functions[i],funcname,funcname,realfunc,funcname);
    //printf("%s\n",function);
    //printf("---------------------------\n");

    fwrite(function,sizeof(char),strlen(function),file);
    fwrite("\n", sizeof(char), 1, file);
  }
fclose(file);
  return 0;
}
