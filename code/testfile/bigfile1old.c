#include "syscall.h"


// create a file "bigf1", which is 9K long.

char buffer[512];


int
main()
{
    int id,id2;
    int i;
    Create("bigf1");
    id = Open("bigf1");

   Write("hello\n",7,ConsoleOutput);

    for (i = 0; i < 512; i++) 
      buffer[i] = 'a' + (i % 26);
   
    //for (i = 0; i < 9*2; i++) 
    for (i = 0; i < 9; i++) 
    	Write(buffer, 512, id);
    Close(id);

   Write("bigf1\n",7,ConsoleOutput);
//   Exit(10);
}
