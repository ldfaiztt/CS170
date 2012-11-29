#include "syscall.h"

// This file tests both Exec and Join with big files;


int
main()
{
    int id;
    Yield();
    id = Exec("bigfile1");
    id = Join(id);
    id = Exec("bigfile2");
    id = Join(id);
    
    Write("Will exit with the same status as the child...\n",48,ConsoleOutput);
    Exit(id);
}

