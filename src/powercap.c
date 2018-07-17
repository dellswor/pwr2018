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
		printf("set value %d\n",PWR_ObjAttrSetValue(o,PWR_ATTR_TEMP,&value));
		printf("powercap should be set\n");
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
	value=atof(argv[0]);
	set_powercap_children(self);
	
}