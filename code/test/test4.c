/* test4.c */
/* --------- testing all system calls       */
/* --------- size of the program : 15 pages */

#include "syscall.h"

char usr_buffer[256];

int main()
{
  int i;
  OpenFileId f0;

  Create( "test4_f0" );
  
  f0 = Open( "test4_f0" );    
  
  Write( "Test4: This is test 4\n", 22, ConsoleOutput );
  Write( "Test4: This is test 4 ( to file 0 )\n", 36, f0 );

  for( i=0 ; i < 256 ; ++i ) usr_buffer[i] = 'A';
    
  Write( usr_buffer, 200, f0 );
  
  Close( f0 );
  
  Exec( "test4_1" );
  
  Halt(0);
}
