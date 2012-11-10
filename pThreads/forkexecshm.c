#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ     27
void exit();
 
char c;
int shmid;
key_t key=1234;
char *shm, *s;

int main(){
  int res=0;
  int status=0;
 
  
  res=fork();
  if (res==0){
    
    /* Locate and attach the segment.  */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        printf("Child: shmget error\n");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("Child: shmat error\n");
        exit(1);
    }
    /* Now read and display them*/
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');

    /* Finally, change the first character of the segment to '*' */
    *shm = '*';
    shmdt(shm);
    exit(0);
  }
    
  if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        printf("Parent: shmget error\n");
        exit(1);
  }
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("Parent: shmat error\n");
        exit(1);
  }
    /*  Now put some things into the memory for the other process to read. */
   s = shm;
   for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
   *s = NULL;

   while (*shm != '*') sleep(1);
  
   wait(&status);
   printf("The parent waits until the completion of  the child process\n");
   shmdt(shm);
   exit(0);
}
