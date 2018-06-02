#include "PluginController.h"
#include "PluginEnumerator.h"
#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <map>
using namespace std;

int main(int argc,char **argv)
{
	// level2: use all dynamic libraries to print respective words.
	char dirPath[50] = "./dl/";
	map<int,void*> map_handle;

	PluginEnumerator pe;
	pe.getPluginMap(map_handle,dirPath);

	PluginController pc;
	pc.execAllPluginFuncPrint(map_handle);
}