/* test5.c */
/* --------- testing system calls : Exit, Exec, Fork */
/* --------- size of the program : 12 pages			      */

#include "syscall.h"

void test5_1 () {
	Write( "Test5 Fork(): This is test 5 after fork before Exec\n", 52, ConsoleOutput );
	Exec( "../test/test5_1" );
        Exit(0);
}

int main()
{
  int i;

  for( i=0 ; i < 2 ; ++i ) {
  	Fork( test5_1);
  	Yield();
  }
  for( i=0 ; i < 2 ; ++i ) Exec( "../test/test5_2" );
  
  Halt(0);
}

