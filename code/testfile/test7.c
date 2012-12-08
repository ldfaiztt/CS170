/* test.c
 *	Simple program to test whether running a user program works.
 *	
 *	be careful to allocate a big enough stack to hold the automatics!
 */

#include "syscall.h"

void foo(int s)
{
  char buf[60];

  Write("in function Foo\n",16,ConsoleOutput);
  Exit(0);
}


int main()
{
     
    Fork(foo);
    Yield();
    
}
