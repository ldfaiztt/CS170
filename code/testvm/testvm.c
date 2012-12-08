#include "syscall.h"


#define SIZE 1024*5

char buffer[SIZE];
char buffer2[SIZE];


int
main()
{
    int id,id2;
    int i;
    Create("in");
    Create("aaaa");
    id = Open("in");
    id2 = Open("aaaa");
    /*    Yield(); */

    for (i = 0; i < SIZE; i++) {
      buffer[i] = 'a' + (i % 26);
    }
    for (i = 0; i < SIZE; i++) {
      buffer2[i] = buffer[i];
    }
    /*    Yield(); */
    Write(buffer2, SIZE, id);
    Write("testvm done\n",13,ConsoleOutput);
    Close(id);
    Close(id2);
    Exit(10);
}


