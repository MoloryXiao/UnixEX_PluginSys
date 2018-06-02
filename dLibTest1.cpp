#include <iostream>
using namespace std;

extern "C" void print()
{
	std::cout<< "Hello World!"<<std::endl;
}
