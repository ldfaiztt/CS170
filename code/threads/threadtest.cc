// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "synch.h"

// testnum is set in main.cc
int testnum = 1;
int workingThreads;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

#if defined(CHANGED) && defined(THREADS)

	#if defined(HW1_SEMAPHORES)
		//extern void Semaphore(char* debugName, int initialValue);
		int SharedVariable;
		Semaphore *sharedVariableSemaphore = new Semaphore("SharedVarSem", 1);
		Semaphore *barrierSemaphore = new Semaphore("BarrerierSem",1);

		void
		SimpleThread(int which)
		{
	  		int num, val;

	 		for(num = 0; num < 5; num++) {
				sharedVariableSemaphore ->P();
	    			val = SharedVariable;

	    			printf("*** thread %d sees value %d\n", which, val);
	    			currentThread->Yield();
	    			SharedVariable = val+1;
				sharedVariableSemaphore ->V();
	    			currentThread->Yield();
				//printf("CurrentThread: %d\n", currentThread);
	  		}
			barrierSemaphore ->P();
			workingThreads--;
			barrierSemaphore ->V();
			while(workingThreads != 0){
				currentThread->Yield();
			}
	  		val = SharedVariable;
			printf("Thread %d sees final value %d\n", which, val);
		}

	#else
		int SharedVariable;

		void
		SimpleThread(int which)
		{
	  		int num, val;

	 		for(num = 0; num < 5; num++) {

	    			val = SharedVariable;
	    			printf("*** thread %d sees value %d\n", which, val);
	    			currentThread->Yield();
	    			SharedVariable = val+1;
	    			currentThread->Yield();
				
	  		}
	  	val = SharedVariable;
	  	printf("Thread %d sees final value %d\n", which, val);
		}
	#endif

#else 

void
SimpleThread(int which)
{
    int num;

    for (num = 0; num < 5; num++) {
        printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}
#endif

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

  #if defined(CHANGED) && defined(THREADS)
    void
	ThreadTest(int n)
	{
    	switch (testnum) {
    	case 1:
		DEBUG('t', "Entering ThreadTest1");
		workingThreads = n + 1;
		for(int i = 1; i < n+1;i++){
			Thread *t = new Thread("forked thread");
			t->Fork(SimpleThread, i);
		}
		SimpleThread(0);		
		break;
    	default:
		printf("No test specified.\n");
		break;
    	}
	}

  #else
     void
	ThreadTest()
	{
    	switch (testnum) {
    	case 1:
		ThreadTest1();
		break;
    	default:
		printf("No test specified.\n");
		break;
    	}
	}

  #endif


#if defined(HW1_LAUNDRY_LC)
// --------------------------- LAUNDROMAT MONITOR ------------------
// This part uses locks and condition variables to synchronize in the laundromat problem. 

Lock *checkLock = new Lock("checkLock");
Condition *cd = new Condition("cd");

#define NMACHINES 10
int freeMachines = NMACHINES;
int available [NMACHINES];


int laundromatAllocate() /* Returns index of available machine. */
{
	checkLock->Acquire();
	while(freeMachines ==0){
		cd->Wait(checkLock);
	}
	
	for(int i = 0; i < NMACHINES; i++){
		if(available[i] == 1){
			available[i] = 0;
			freeMachines--;
			checkLock->Release();
			return i;
		}
	}
	return -1;
}
void laundromatRelease(int machine) /* Release machine */
{

	checkLock->Acquire();
	available[machine] = 1;
	freeMachines++;
	cd->Signal(checkLock);
	checkLock->Release();

}


void laundromatCustomer(int customerNumber)
{
    for(int i=0; i<6; i++)
    {
        int assignedMachine = laundromatAllocate();
        printf("Station %d assigned machine %d\n", customerNumber, assignedMachine);
        laundromatRelease(assignedMachine);
        printf("Machine %d has been released\n", assignedMachine);
    }
}

void runStationOne(int stationNumber)
{
    //We have 10 machines. Station 1 needs to allocate 7 machines.

    // Station 1 gets 3 machines then Yields
    int assignedMachine1 = laundromatAllocate();    printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine1, freeMachines);
    int assignedMachine2 = laundromatAllocate();    printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine2, freeMachines);
    int assignedMachine3 = laundromatAllocate();     printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine3, freeMachines);
    currentThread->Yield();

    // Station 1 gets 4 machines then Yields
    int assignedMachine4 = laundromatAllocate();     printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine4, freeMachines);
    int assignedMachine5 = laundromatAllocate();     printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine5, freeMachines);
    int assignedMachine6 = laundromatAllocate();     printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine6, freeMachines);
    int assignedMachine7 = laundromatAllocate();     printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine7, freeMachines);
    currentThread->Yield();

    // Station 1 releases 2 machines and Yealds
    laundromatRelease(assignedMachine1);             printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine1, freeMachines);
    laundromatRelease(assignedMachine2);             printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine2, freeMachines);
    laundromatRelease(assignedMachine3);             printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine3, freeMachines);
    currentThread->Yield();
    // At this point Station 2 has enough resaurces to continue allocation

    // Station 1 releases 2 machines and Yealds
    laundromatRelease(assignedMachine4);            printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine4, freeMachines);
    laundromatRelease(assignedMachine5);            printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine5, freeMachines);
    laundromatRelease(assignedMachine6);            printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine6, freeMachines);
    laundromatRelease(assignedMachine7);            printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine7, freeMachines);
    // Station 1 is done
    printf("Station 1 is done!\n");
}

void runStationTwo(int stationNumber)
{
    //We have 10 machines. Station 2 needs to allocate 6 machines.

    // Station 2 gets 2 machines then Yields
    int assignedMachine1 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine1, freeMachines);
    int assignedMachine2 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine2, freeMachines);
    currentThread->Yield();
    // S1: has(2) needs(4)

    // Station 2 will try to get 4 more machines but there is only one left
    // so it will go to sleep after the first allocation and wait for Station 1
    // to release the resources
    int assignedMachine3 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine3, freeMachines);
    int assignedMachine4 = laundromatAllocate(); //This is where Station 2 should be sleeping
    printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine4, freeMachines);
    int assignedMachine5 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine5, freeMachines);
    int assignedMachine6 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine6, freeMachines);
    currentThread->Yield();

    //Station 2 will release all its machines
    laundromatRelease(assignedMachine1);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine1, freeMachines);
    laundromatRelease(assignedMachine2);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine2, freeMachines);
    laundromatRelease(assignedMachine3);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine3, freeMachines);
    laundromatRelease(assignedMachine4);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine4, freeMachines);
    laundromatRelease(assignedMachine5);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine5, freeMachines);
    laundromatRelease(assignedMachine6);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine6, freeMachines);
    //Station 2 is done
    printf("Station 2 is done!\n");
}

void runStationThree(int stationNumber)
{
    //We have 10 machines. Station 3 needs to allocate 5 machines.

    // Station 3 gets 1 machines then Yields
    int assignedMachine1 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine1, freeMachines);
        currentThread->Yield();
    // S3: has(1) needs(4)

    // Station 3 will try to get 4 more machines but there is only one left
    // so it will go to sleep after the first allocation and wait for Station 1
    // to release the resources
    int assignedMachine2 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine2, freeMachines);
    int assignedMachine3 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine3, freeMachines);
    int assignedMachine4 = laundromatAllocate();     	printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine4, freeMachines);
    int assignedMachine5 = laundromatAllocate();        printf("Station %d assigned machine %d (%d machines left)\n", stationNumber, assignedMachine5, freeMachines);
    currentThread->Yield();

    //Station 3 will release all its machines
    laundromatRelease(assignedMachine1);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine1, freeMachines);
    laundromatRelease(assignedMachine2);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine2, freeMachines);
    laundromatRelease(assignedMachine3);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine3, freeMachines);
    laundromatRelease(assignedMachine4);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine4, freeMachines);
    laundromatRelease(assignedMachine5);                printf("Station %d released machine %d (%d machines left)\n", stationNumber, assignedMachine5, freeMachines);
    
    //Station 3 is done
    printf("Station %s is done!\n",stationNumber);
}
void runStation(int stationNumber, int machinesNeeded){
	int assignedMachines [machinesNeeded];	
	for(int i=0;i<machinesNeeded;i++){
		
	}
	for(int i=0;i<machinesNeeded;i++){
		
	}
	printf("Station %d is done!\n");
}
void laundromatTest()
{
    // Mark all of the machines as available
    for(int i=0; i<NMACHINES; i++)
        available[i] = 1;

    	Thread *station1 = new Thread("Laundromat station 1");
    	Thread *station2 = new Thread("Laundromat station 2");
	Thread *station3 = new Thread("Laundromat station 3");
	station1->Fork(runStationOne, 1);
	station2->Fork(runStationTwo, 2);
	station3->Fork(runStationThree, 3);	
	//station3->Fork(runStation, 3,5);
	//station3->Fork(runStation, {3,4});
	
}




#endif


