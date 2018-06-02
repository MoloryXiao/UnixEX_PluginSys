#include <iostream>
using namespace std;

int id = 2;

extern "C" void print()
{
	cout<< "Hello China!"<<endl;
}

extern "C" int getDLL_ID()
{
	return id;
}

extern "C" void help()
{
	cout<<"DLL_ID = "<<getDLL_ID()<<": print 'Hello China!'"<<endl;
}