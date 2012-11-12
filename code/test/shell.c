#include "syscall.h"

int main()
{
    SpaceId newProc;
    OpenFileId output = ConsoleOutput;

	Write("Before join\n", 11, output);
	newProc = Exec("hello1");
	Join(newProc);
	Write("After join\n", 11, output);
}

