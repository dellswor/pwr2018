#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

#include <msr_core.h>
#include <msr_rapl.h>

#define INTERVAL_SEC 0
#define INTERVAL_NANO 100000000

static int inite;

PWR_Grp     grp;
PWR_Obj     self;
PWR_Cntxt   cntxt;
PWR_Time ts;
int         rc;
double value;
int powerlogfd;
FILE *powerlogfile=NULL;


int measure_children(PWR_Obj o)
{
	inite = 0;

	PWR_ObjAttrGetValue( self, PWR_ATTR_ENERGY, &value, &ts );
	char name[100];
	PWR_ObjGetName( o, name, 100 );
	fprintf(powerlogfile,"ENERGY, %f joules, %lu ms, %s\n", value, ms_now(), name);


	PWR_ObjType objType;
	PWR_ObjGetType( o, &objType );
	if(objType==PWR_OBJ_NODE)
	{
		return 0;
	}
	else
	{
		PWR_Grp children;
		PWR_ObjGetChildren( o, &children );
		int childrenNum = PWR_GrpGetNumObjs(children);
		printf("children loop childrenNum is %i\n", childrenNum);
		for (int i = 0; i < childrenNum; i++ ) {
			PWR_Obj child;
			PWR_GrpGetObjByIndx( children, i, &child );
			printf("i is %i\n",i);
			measure_children(child);
		}
		//return 1;
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
	//recursively take measurements of children
	measure_children(self);
	return 0;
}
void *power_measurement(void *arg)
{

	powerlogfd=open("power.dat",O_WRONLY|O_CREAT|O_NDELAY, S_IRUSR|S_IWUSR);
	if(powerlogfd<0)
	{
		printf("failed to get file descriptor: %i, errno: %i\n",powerlogfd,errno);
	}
	powerlogfile = fdopen(powerlogfd, "w");
	if(powerlogfile==NULL)
	{
		printf("failed to open erno is %i\n",errno);
	}

	// Get a context
	rc = PWR_CntxtInit( PWR_CNTXT_VENDOR, PWR_ROLE_MC, "Monitor", &cntxt );
	rc = PWR_CntxtGetEntryPoint( cntxt, &self );
	static struct rapl_limit rlim[2];
	rlim[0].watts = 10;
	rlim[1].watts = 10;
	rlim[0].bits = 0;
	rlim[1].bits = 0;
	rlim[0].seconds = 1;
	rlim[1].seconds = 1;
	int r;
	PWR_ObjType objType;
	PWR_ObjGetType( self, &objType );
	//set self to highest level in hierarchy
	while(objType!=PWR_OBJ_PLATFORM)
	{
		PWR_ObjGetParent( self, &self );
		PWR_ObjGetType( self, &objType );
	}
	PWR_Grp children;
	PWR_ObjGetChildren( self, &children );
	PWR_Obj child;
	PWR_GrpGetObjByIndx( children, 0, &child );

	PWR_ObjAttrSetValue( child,PWR_ATTR_POWER_LIMIT_MAX, rlim );


	while(monitoring)
	{

		measure_energy();
		sleep_abs(INTERVAL_NANO);
	}
	fclose(powerlogfile);
	close(powerlogfd);

}
