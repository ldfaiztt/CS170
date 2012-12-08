#include "syscall.h"


// create a file "bigf2", which is 40K long.

char buffer[512];


int
main()
{
    int id,id2;
    int i;
    Create("bigf2");
    id = Open("bigf2");


    for (i = 0; i < 512; i++) 
      buffer[i] = 'a' + (i % 26);
   
    for (i = 0; i < 80; i++) 
    	Write(buffer, 512, id);
    Close(id);

   Write("bigf2\n",6,ConsoleOutput);
   Exit(10);
}
