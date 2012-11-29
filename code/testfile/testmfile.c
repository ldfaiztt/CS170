
#include "syscall.h"

// create 40 files 

char buffer[128];

create10files(c)
char c;
{
    char name[3];
    int id, i;

    name[0]=c;
    name[2]='\n';
    for (i = 0; i < 10; i++) {
    	name[1]=i+'0';
    	Create(name);
    	id = Open(name);
    	Write(buffer, 128, id);
    	Write(buffer, 128, id);

	Close(id);

   }

}
main()
{
    int f0;
    int i;
    char  name[4], b[10];

    for (i = 0; i < 128; i++) 
      buffer[i] = 'a' + (i % 26);

    create10files('r');
    create10files('s');
    create10files('t');
    create10files('u');

    f0 = Open("u9");    
    Read( b, 10, f0);
    Write("testmfile:",10,ConsoleOutput);
    Write(b, 10, ConsoleOutput);
    Write("\n:",1,ConsoleOutput);
    Exit(10);
}
