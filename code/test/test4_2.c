/* test4_2.c */
/* --------- testing all system calls       */
/* --------- size of the program : 14 pages */

#include "syscall.h"

char usr_buffer[256];

int main()
{
  int i;
  
  Write( "Test4: This is test 4_2\n", 36, ConsoleOutput );
  Write( "Please Input 5 characters : \n", 32, ConsoleOutput );
  
  for( i=0 ; i < 256 ; ++i ) usr_buffer[i] = 'A';
  
  Read( usr_buffer, 5, ConsoleInput );
  Write( usr_buffer, 200, ConsoleOutput );
}
