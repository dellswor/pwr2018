#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwr.h>
double value;
int set_powercap_children(PWR_Obj o)
{
	PWR_ObjType objType;
	PWR_ObjGetType( o, &objType );
	if(objType==PWR_OBJ_NODE)
	{
		printf("Power cap should be set to %lf\n",value);

		PWR_ObjAttrSetValue(o,PWR_ATTR_POWER_LIMIT_MAX,&value);
		double val;
		PWR_Time ts;
		PWR_ObjAttrGetValue(o, PWR_ATTR_POWER_LIMIT_MAX,&val,&ts);
		printf("Power cap set to %lf\n",val);
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
			set_powercap_children(child);
		}
	}
	return 0;
}
int main(int argc, char **argv){
	PWR_Obj self;
	PWR_Cntxt cntxt;
	PWR_CntxtInit( PWR_CNTXT_DEFAULT, PWR_ROLE_APP, "App", &cntxt );
	PWR_CntxtGetEntryPoint( cntxt, &self );
	PWR_ObjType objType;
	PWR_ObjGetType( self, &objType );
	value=atof(argv[1]);
	set_powercap_children(self);
	
}
