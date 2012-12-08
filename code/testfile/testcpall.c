#include "syscall.h"


void func();

int
main()
{
    Fork(func);
    Exit(1);
}

void func()
{
    int id;
    
    id = Exec("bigfile1");
    Join(id);

    id = Exec("cpbig");
    id = Join(id);
    Write("TestCP child...\n",48,ConsoleOutput);
    Exit(id);
}
