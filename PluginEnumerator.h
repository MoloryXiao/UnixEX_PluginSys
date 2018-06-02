#pragma once

#include <iostream>
#include <map>
using namespace std;

class PluginEnumerator
{
public:
	bool getPluginMap(map<int,void*>& map_handle,char dirPath[50]);
};