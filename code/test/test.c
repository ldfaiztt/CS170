#include "syscall.h"

void test_function1()
{

  Write("# FORKED 1-1 !!\n", 20, ConsoleOutput);

/* ensure that TEST1 is loaded before this function finishes */  
  Yield();
  Yield();
  
  Write("# FORKED 1-2 !!\n", 23, ConsoleOutput);
  Exit(1);
}

void
main()
{
   
    OpenFileId OutFid, InFid;
    int ret =335;
    int size = 9;
    int stub =3;
    char buffer[20];
    
    Create("out");
    Create("out1");
    
    OutFid = Open("out");    
    Write("Test: First write!\n", 21, ConsoleOutput);
    
    Read(buffer, size, ConsoleInput);
    Write(buffer, size, ConsoleOutput);
    
    Yield(); 
    Write("Test: Second write!\n", 22, OutFid);
	
	Close(OutFid);
	
    Fork(test_function1);
    Exec("test1");

}
