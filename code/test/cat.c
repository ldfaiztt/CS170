#include "syscall.h"

int main() {

  char buf[10];
  SpaceId dst, src;
  int count;
 
  src = Open("out");
  if (src < 0) Exit(100);
 
  while ((count = Read(buf, 5, src))>0) 
    Write(buf, count, ConsoleOutput);
   
  Write("cat: file is over. \n", 20, ConsoleOutput);
  Exit(200);
 
}

