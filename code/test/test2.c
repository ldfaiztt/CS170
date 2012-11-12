/* test2.c */
/* --------- testing console Read and Write */
/* --------- size of the program : 16 pages */

#include "syscall.h"

char usr_buffer_0[256];
char usr_buffer_1[256];

int main()
{
  int i;
  
  Write( "Test2: This is test 2\n", 22, ConsoleOutput );

  for( i=0 ; i < 256 ; ++i ) 
     {
       usr_buffer_0[i] = 'A';
       usr_buffer_1[i] = 'B';
     }
    
  Write( usr_buffer_0, 200, ConsoleOutput );
  Read( usr_buffer_1, 3, ConsoleInput );
  Write( usr_buffer_1, 200, ConsoleOutput );
    
  Halt(0);
}
