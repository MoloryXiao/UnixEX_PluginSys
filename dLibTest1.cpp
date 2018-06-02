#include <iostream>
using namespace std;

int id = 1;

extern "C" void print()
{
	std::cout<< "Hello World!"<<std::endl;
}

extern "C" int getDLL_ID()
{
	return id;
}