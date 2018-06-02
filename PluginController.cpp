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
	
	return
		true;
}

bool PluginController::execAllPluginFuncHelp(map<int,void*>& map_handle)
{
	map<int,void*>::iterator iter;
	typedef void (*FUNC_HELP)();

	for(iter = map_handle.begin();iter != map_handle.end();iter++)
	{
		FUNC_HELP dl_help = (FUNC_HELP)dlsym(iter->second,"help");
		if(0 == dl_help)
		{
			cout<< "dl_help error" <<endl;
			char *str = dlerror();
			cout<< str <<endl;
			continue;
		}
		(*dl_help)();
	}
	return true;
}

bool PluginController::execPluginFuncPrint(map<int,void*>& map_handle,int id)
{
	int res = map_handle.count(id);
	if(res == 0)
		return false;

	typedef void (*FUNC_PRINT)();
	FUNC_PRINT dl_print = (FUNC_PRINT)dlsym(map_handle[id],"print");
	if(0 == dl_print)
	{
		cout<< "dl_print error" <<endl;
		char *str = dlerror();
		cout<< str <<endl;
	}
	(*dl_print)();
	return true;
}