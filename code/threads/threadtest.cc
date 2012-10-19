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

// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------
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


