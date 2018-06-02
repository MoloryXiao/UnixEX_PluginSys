#include "PluginController.h"
#include "PluginEnumerator.h"
#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <map>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc,char **argv)
{
	// level3: Use the corresponding dynamic link library based on the given ID.
	if(argc != 2)
		return 0;

	char dirPath[50] = "./dl/";
	map<int,void*> map_handle;

	PluginEnumerator pe;
	pe.getPluginMap(map_handle,dirPath);

	PluginController pc;

	if(strcmp(argv[1],"help") == 0)
	{
		cout<<"---------- HELP ----------"<<endl;
		pc.execAllPluginFuncHelp(map_handle);
	}
	else
	{
		int funcID = atoi(argv[1]);
		if(!pc.execPluginFuncPrint(map_handle,funcID))
			cout<<"Error: execPluginFuncPrint( id = "<<funcID<<" )"<<endl;
	}
}