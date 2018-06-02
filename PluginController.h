#pragma once

#include <iostream>
#include <map>
using namespace std;

class PluginController
{
public:
	bool execAllPluginFuncPrint(map<int,void*>& map_handle);
	bool execAllPluginFuncHelp(map<int,void*>& map_handle);
	bool execPluginFuncPrint(map<int,void*>& map_handle,int id);
};