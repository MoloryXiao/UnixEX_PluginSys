#include "PluginController.h"
#include <map>
#include <iostream>
#include <dlfcn.h>
using namespace std;

bool PluginController::execAllPluginFuncPrint(map<int,void*>& map_handle)
{
	typedef void (*FUNC_PRINT)();
	map<int,void*>::iterator iter;

	for(iter = map_handle.begin();iter != map_handle.end();iter++)
	{
		FUNC_PRINT dl_print = (FUNC_PRINT)dlsym(iter->second,"print");
		if(0 == dl_print)
		{
			cout<< "dl_print error" <<endl;
			char *str = dlerror();
			cout<< str <<endl;
			continue;
		}
		(*dl_print)();
	}
	
	return true;
}