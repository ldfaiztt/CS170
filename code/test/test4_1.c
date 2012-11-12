/* test4_1.c */
/* --------- testing all system calls       */
/* --------- size of the program : 14 pages */

#include "syscall.h"

char usr_buffer[256];

int main()
{
  int i;
  OpenFileId f0, f1;
  
  Create( "test4_f1" );
  
  f0 = Open( "test4_f0" );    
  f1 = Open( "test4_f1" );
  
  Read( usr_buffer, 200, f0 );
  Write( "Test4: This is test 4_1\n", 36, f0 );
  Write( usr_buffer, 200, f1 );

  Close( f0 );
  Close( f1 ); 
    
  Exec( "test4_2" );

  Close( f0 );
  Close( f1 );
}
