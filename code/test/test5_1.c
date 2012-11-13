/* test5_1.c */
/* --------- testing system calls : Exit, Exec, Fork */
/* --------- size of the program : 11 pages          */

#include "syscall.h"

int main()
{
  Write( "Test5: This is test 5_1\n", 24, ConsoleOutput );
  Exit( 0 );
}
