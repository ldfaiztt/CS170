/* test3_1.c */
/* --------- testing system calls : Exit, Exec, Join */
/* --------- size of the program : 11 pages          */

#include "syscall.h"

int main()
{
  Write( "Test3: This is test 3_1\n", 24, ConsoleOutput );
  Exit( 0 );
}
