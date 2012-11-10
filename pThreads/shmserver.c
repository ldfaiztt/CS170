#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27
void exit();

main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /*  We'll name our shared memory segment  "5678". */
    key = 5678;

    /*  Create the segment. */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        printf("server: shmget error\n");
        exit(1);
    }


 /* Now we attach the segment to our data space. */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        printf("server: shmat error\n");
        exit(1);
    }

    /*  Now put some things into the memory for the other process to read. */

    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = NULL;

    /* Finally, we wait until the other process changes the first character of our memory
 	to '*', indicating that it has read what we put there. */
    while (*shm != '*') sleep(1);

      /* A shared memory object is only removed after all currently attached processes have
	detached (shmdt(2)) the object from their virtual address space. */

    shmdt(shm);

    exit(0);
}
