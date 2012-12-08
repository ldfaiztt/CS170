#include "syscall.h"

int main() {

  char buf[10];
  SpaceId dst, src;
  int count;
 
  src = Open("bigf1");  /*make sure this file exists in the Nachos file system*/
  if (src < 0) {
  	Write("cpbig: bigfg1 is not found.\n", 22, ConsoleOutput);
	Exit(100);
   }

  Create("bigf1out");
  dst = Open("bigf1out");
  if (dst < 0) Exit(200);
 
  while ((count = Read(buf, 5, src))>0) 
    Write(buf, count, dst);
   
  Write("cpbig: file is copied. \n", 24, ConsoleOutput);

  Close(src);
  Close(dst);
  Exit(300);
 
}

