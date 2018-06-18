#include "/home/kona/pwr2018/pwrapi-ref/src/pwr/pwr.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>


#define INTERVAL_SEC 0
#define INTERVAL_NANO 100000000

static int inite;

PWR_Grp     grp;
PWR_Obj     self;
PWR_Cntxt   cntxt;
PWR_Time ts;
int         rc;
double value;

int measure_children(PWR_Obj o)
{
  inite = 0;
  if(PWR_ObjAttrIsValid(o,PWR_ATTR_ENERGY)==PWR_RET_SUCCESS)
  {
    int r = PWR_ObjAttrSetValue( self, PWR_ATTR_ENERGY, &inite);
    r = PWR_ObjAttrGetValue( self, PWR_ATTR_ENERGY, &value, &ts );
    char buffer[1000];
    char name[100];
    PWR_ObjGetName( o, name, 100 );
    sprintf(buffer,"%f joules, %lu ms, %s\n",	value, ms_now(), name);
    write_data(buffer,"ENERGY");
  }

  PWR_ObjType objType;
  PWR_ObjGetType( o, &objType );
  if(objType==PWR_OBJ_CORE)
    return 0;
  else
  {
    PWR_Grp children;
    PWR_ObjGetChildren( o, &children );
    for (int i = 0; i < PWR_GrpGetNumObjs(children); i++ ) {
      PWR_Obj child;
        PWR_GrpGetObjByIndx( children, i, &child );
      return measure_children(child);
    }
  }
}
int measure_energy()
{
  PWR_ObjType objType;
  PWR_ObjGetType( self, &objType );
  //set self to highest level in hierarchy
  while(objType!=PWR_OBJ_PLATFORM)
  {
    PWR_ObjGetParent( self, &self );
    PWR_ObjGetType( self, &objType );
  }
  //printf("set self to platform\n");
  measure_children(self);
  return 0;
}
void *power_measurement(void *arg)
{
  //fprintf(logfile,"monitoring starts in power profiler %lu\n", ms_now()/1000);
  // Get a context
  rc = PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_APP, "App", &cntxt );
  rc = PWR_CntxtGetEntryPoint( cntxt, &self );

  while(monitoring)
  {
    //printf("measuring\n");
    measure_energy();
    sleep_abs(INTERVAL_NANO);
  }
  //fprintf(logfile,"monitoring ends in power profiler %lu\n", ms_now()/1000);

}
