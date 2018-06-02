#include <iostream>
using namespace std;

int id = 1;

extern "C" void print()
{
	cout<< "Hello World!"<<endl;
}

extern "C" int getDLL_ID()
{
	return id;
}

extern "C" void help()
{
	cout<<"DLL_ID = "<<getDLL_ID()<<": print 'Hello World!'"<<endl;
}