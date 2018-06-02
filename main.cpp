#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
using namespace std;

int main(int argc,char **argv)
{
	// level1: use dynamic linking library to achieve printing a word.
	void *handle = dlopen("./dl/dLibTest1.so",RTLD_LAZY);
	if(0 == handle)
	{
		cout << "dlopen error" <<endl;
		return 0;
	}

	typedef void (*FUNC_PRINT)();

	FUNC_PRINT dl_print = (FUNC_PRINT)dlsym(handle,"print");

	if(0 == dl_print)
	{
		cout<< "dl_print error" <<endl;
		char *str = dlerror();
		cout<< str <<endl;
	}

	(*dl_print)();

	dlclose(handle);
}