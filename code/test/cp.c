#include "syscall.h"

int main() {

  char buf[10];
  SpaceId dst, src;
  int count;
 
  src = Open("in");
  if (src < 0) Exit(100);

  Create("out");
  dst = Open("out");
  if (dst < 0) Exit(200);
 
  while ((count = Read(buf, 5, src))>0) 
    Write(buf, count, dst);
   
  Write("cp: file is copied. \n", 21, ConsoleOutput);
  Exit(300);
 
}

