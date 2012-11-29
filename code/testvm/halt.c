/* halt.c
 *	Simple program to test whether running a user program works.
 *	
 *	Just do a "syscall" that shuts down the OS.
 *
 * 	NOTE: for some reason, user programs with global data structures 
 *	sometimes haven't worked in the Nachos environment.  So be careful
 *	out there!  One option is to allocate data structures as 
 * 	automatics within a procedure, but if you do this, you have to
 *	be careful to allocate a big enough stack to hold the automatics!
 */

#include "syscall.h"

void myFork()
{
	Write("I am your champion, I am here to save you ... \n", 25, ConsoleOutput);
	Exit(123);
}

int
main()
{
	int childPid, numCharsRead, fid;
	char readBuffer[12];
	Create("winzorz");
	fid = Open("winzorz");
	// Die if could not open file
	if(fid == -1)
		Exit(1);
	Write("What what?", 10, fid);
	numCharsRead =	Read(readBuffer, 11, fid);
	Write(readBuffer, numCharsRead, ConsoleOutput);
	
	Close(fid);
	fid = Open("winzorz");
	if(fid == -1)
		Exit(2);
	numCharsRead =	Read(readBuffer, 11, fid);
	Write(readBuffer, numCharsRead, ConsoleOutput);

	Fork(myFork);

   	Exit(0);
    /* not reached */
}
