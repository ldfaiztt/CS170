#include "syscall.h"

int main() {

  char buf[10];
  SpaceId dst, src;
  int count;
 
  src = Open("in1");  /*make sure that file in1 exists in the Nachos file system*/
  if (src < 0) {
  	Write("cp: in1 is not found.\n", 22, ConsoleOutput);
	Exit(100);
   }

  Create("out");
  dst = Open("out");
  if (dst < 0) Exit(200);
 
  while ((count = Read(buf, 5, src))>0) {
    Write(buf, count, dst);
}
   
  Write("cp: file is copied. \n", 21, ConsoleOutput);

  Close(src);
  Close(dst);
  Exit(300);
 
}

