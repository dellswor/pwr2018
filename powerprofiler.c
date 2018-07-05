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
double value;
int powerlogfd;
FILE *powerlogfile=NULL;

int write_data(PWR_Obj o)
{
	PWR_ObjAttrGetValue( o, PWR_ATTR_ENERGY, &value, &ts );
	fprintf(powerlogfile,"%lu %f %s\n",ms_now(), value, hostname);
	return 0;
}
int measure_children(PWR_Obj o)
{
	PWR_ObjType objType;
	PWR_ObjGetType( o, &objType );
	if(objType==PWR_OBJ_NODE)
	{
		write_data(o);
		return 0;
	}
	else
	{
		PWR_Grp children;
		PWR_ObjGetChildren( o, &children );
		int childrenNum = PWR_GrpGetNumObjs(children);
		for (int i = 0; i < childrenNum; i++ ) {
			PWR_Obj child;
			PWR_GrpGetObjByIndx( children, i, &child );
			measure_children(child);
		}
	}
	return 0;
}
int measure_energy()
{
	PWR_ObjType objType;
	PWR_ObjGetType( self, &objType );
	if(objType==PWR_OBJ_NODE)
	{
		write_data(self);
		return 0;
	}
	else
	{
		//set self to highest level in hierarchy
		while(objType!=PWR_OBJ_PLATFORM)
		{
			PWR_ObjGetParent( self, &self );
			PWR_ObjGetType( self, &objType );

		}
		measure_children(self);
	}
	return 0;
}

void *power_measurement(void *arg)
{
	char name[30];
	sprintf(name, "%s/energy.%s.dat",pathname,hostname);
	powerlogfd=open(name,O_WRONLY|O_CREAT|O_NDELAY, S_IRUSR|S_IWUSR);

	if(powerlogfd<0)
	{
		printf("open failed in %s. %s\n",__FILE__,strerror(errno));
		exit(EXIT_FAILURE);
	}
	powerlogfile = fdopen(powerlogfd, "w");
	if(powerlogfile==NULL)
	{
		printf("fdopen failed in %s. %s\n",__FILE__,strerror(errno));
		exit(EXIT_FAILURE);
	}
	fprintf(powerlogfile,"time(ms) energy(J) hostname\n");
	// Get a context
	PWR_CntxtInit( PWR_CNTXT_VENDOR, PWR_ROLE_MC, "Monitor", &cntxt );
	PWR_CntxtGetEntryPoint( cntxt, &self );
	static struct rapl_limit rlim;


	rlim.watts = atof(getenv("PROFILER_POWERCAP"));
	rlim.bits = 0;
	rlim.seconds = 1;
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

	//PWR_ObjAttrSetValue( child,PWR_ATTR_POWER_LIMIT_MAX, &rlim );
	timer_init(atoi(getenv("PROFILER_FREQUENCY")));
	while(monitoring)
	{
		measure_energy();
		timer_sleep();
	}
	fclose(powerlogfile);
	close(powerlogfd);
	int threadret=0;
	pthread_exit(&threadret);
}
