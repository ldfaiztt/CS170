#include "syscall.h"

void test_function2()
{
  int i=0;
  
  OpenFileId OutFid, InFid;

  Write("# FORKED 2-1 !!\n", 20, ConsoleOutput);
  Write("# FORKED 2-2 !!\n", 23, ConsoleOutput);
  
  /* maintain this function in memory */
  for( i=0 ; i < 10 ; ++i ) Yield();

  Exit(1);  
}

void test_function3()
{

  Write("# FORKED 3-1 !!\n", 22, ConsoleOutput);
  Write("# FORKED 3-2 !!\n", 25, ConsoleOutput);
  Yield();
  Exit(1);  
}

char temp[2500];
int
main()
{
   
    OpenFileId OutFid, InFid;
    int ret =335;
    int size = 9;
    int stub =3;
    char buffer[20];
    
    InFid = Open("out");    
    OutFid = Open("out1");
    
    Write("Test1: First write!\n", 253, ConsoleOutput);
    
    Fork(test_function2);
    
    Write("This is Test1\n", 21, OutFid);
    
    Read(buffer, size, InFid);
    Write(buffer, size, OutFid);
    Yield(); 

    Write("Second write!\n", 22, OutFid);

	Fork(test_function3);

    Yield();
    Write("Third write!\n", 24, OutFid);
    Close(InFid);
    Close(OutFid);
    
	Exec("mix_test2");  
    Exit(0);  
/* following code is not reached */
/* it is put here just to consume some memory space*/
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);
  Write("Something's WRONG !!\n", 22, ConsoleOutput);

}
