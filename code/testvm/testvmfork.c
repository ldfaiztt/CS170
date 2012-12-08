#include "syscall.h"

// This test will fork 2 child process in a chain. Each process will 
// print out their own messages;

// Also, we defined a dummy array to stress the memory usage.

void forkedfunc();
void forkedfunc2();

char buffer[1024*5];

main()
{
    Write("Main\n", 7, ConsoleOutput);
    Fork(forkedfunc);
    Write("Main-2\n", 7, ConsoleOutput);
    Exit(0);
}


void forkedfunc()
{
    Fork(forkedfunc2);
    Write("Forked 1\n", 11, ConsoleOutput);
    Exit(1);    
}

void forkedfunc2()
{
    Write("Forked 2\n", 11, ConsoleOutput);
    Exit(2);    
};
