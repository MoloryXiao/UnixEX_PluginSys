#pragma once

#include <iostream>
#include <map>
using namespace std;

class PluginController
{
public:
	bool execAllPluginFuncPrint(map<int,void*>& map_handle);
};