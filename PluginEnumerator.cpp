#include "PluginEnumerator.h"
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
using namespace std;

bool PluginEnumerator::getPluginMap(map<int, void *>& map_handle,char dirPath[50])
{
	DIR *dir;
	struct dirent* ptr;
	typedef int (*FUNC_GETID)();

	dir = opendir(dirPath);
	while( (ptr=readdir(dir))!= NULL )	// search all 'file.so' in directory of dynamic linking lib.
	{
		char filePath[50];
		strcpy(filePath,dirPath);
		if(strcmp(ptr->d_name,".") && strcmp(ptr->d_name,".."))	// exclude current dir and previous dir
		{
			strcat(filePath,ptr->d_name);
			void* handle = dlopen(filePath,RTLD_LAZY);

			if(0 == handle)
			{
				cout << filePath << ": dlopen error" <<endl;
				continue;
			}			

			FUNC_GETID dl_getID = (FUNC_GETID)dlsym(handle,"getDLL_ID");	// get FUNC_GETID according to handle
			if(0 == dl_getID)
			{
				cout<< filePath << ": dl_getID error" <<endl;
				char *str = dlerror();
				cout<< str <<endl;
				continue;
			}
			int id = (*dl_getID)();		// get id from FUNC_GETID
			map_handle[id] = handle;	// link id and handle
			cout<< "Info: load the dynamic linking lib '"<<filePath<<"'    OK"<<endl;
		}
	}
	closedir(dir);
	return true;
}
