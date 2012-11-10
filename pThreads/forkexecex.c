#include <stdio.h>
#include <unistd.h>

// This example demomstrates how the fork(), exec(), and wait system calls are used to create processes on Unix.
// http://www.sheriffadelfahmy.org/blog/using-fork-and-exec-on-linux/

//When this function finishes executing, there will be two processes in the system. 
//Therefore, the fork() function returns in two processes; the original process, and the newly created process.


// int execl(const char *path, const char *arg, ...);
//The first parameter, path, is the path containing the binary file we would like to load (including it.s name). 
// The second parameter, arg, is the name of the executable, other arguments, all of type char *, 
// represent the command line parameters you want to send to the new executable.
 
int main(){
  int res=0;
  int status=0;
 
  char *path = "/bin/ls";
  char *arg0 = "ls";
  char *arg1 = "-l";
 
  printf("This is  before call to fork()\n");
  res=fork();
  if (res==0){
    printf("I am now in the child process\n");
    execl(path,arg0,arg1,NULL);
  }else
    printf("I am now in the parent process\n");
  wait(&status);
  printf("The parent waits until the completion of  the child process\n");
}
