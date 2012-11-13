/* test3.c */
/* --------- testing system calls : Exit, Exec, Join */
/* --------- size of the program : 12 pages			      */

#include "syscall.h"

int main()
{
  int i, x;
  x = 100;

  for( i=0 ; i < 5 ; ++i ) Exec( "../test/test3_1" );
 
  for( i=0 ; i < 5 ; ++i ) Join( Exec( "../test/test3_2" ) );

  x = 400;
  
  Halt(0);
}
