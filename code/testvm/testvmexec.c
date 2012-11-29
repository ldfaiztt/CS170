#include "syscall.h"

// This file tests both Exec and Join;

// Note: this test should be called from code/vm, because the filename
// is dependent on that;

int buffer[1500];

int
main()
{
    int id;
    Yield();
    id = Exec("../test/matmult1");
    id = Join(id);
    id = Exec("../test/testvmfork");
    id = Join(id);
    
    Write("Will exit with the same status as the child...\n",48,ConsoleOutput);
    Exit(id);
}

