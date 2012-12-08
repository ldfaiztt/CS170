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

#if !defined(CHANGED) && (defined(HW1_SEMAPHORES) || defined(HW1_LOCKS) || defined(HW1_CONDITION))
# error CHANGED not defined, but HW1_SEMAPHORES or HW1_CONDITION or HW1_LOCKS defined
#endif

#if defined(CHANGED) && defined(HW1_SEMAPHORES)
# if defined(HW1_LOCKS) || defined(HW1_CONDITION)
#  error Can't do HW1_SEMAPHORES and other stuff at the same time
# endif
#endif

#if defined(CHANGED) && defined(HW1_LOCKS)
# if defined(HW1_SEMAPHORES) || defined(HW1_CONDITION)
#  error Can't do HW1_LOCKS and other stuff at the same time
# endif
#endif

#if defined(CHANGED) && defined(HW1_CONDITION)
# if defined(HW1_LOCKS) || defined(HW1_SEMAPHORES)
#  error Can't do HW1_CONDITION and other stuff at the same time
# endif
#endif

#include "copyright.h"
#include "system.h"
#ifdef CHANGED
# include "synch.h"
# ifdef HW1_TASK4
#  include <sys/time.h>
# endif
#endif

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
#ifdef HW1_SEMAPHORES
int finished;
Semaphore FinishedSemaphore("finished", 1);
Semaphore VarSemaphore("SharedVariable", 1);
#elif defined(HW1_LOCKS)
int finished;
Lock FinishedLock("finished");
Lock VarLock("SharedVariable");
#elif defined(HW1_CONDITION)
int avail;
Lock ConditionLock("avail");
Condition AvailCondition("ConditionLock");
#endif

#ifdef CHANGED
#ifdef HW1_CONDITION
void ConditionThread(int which) {
    int i, j;
    DEBUG('c', "Got avail = %d\n", avail);
    for (i = 0; i < 200; i++) {
        ConditionLock.Acquire();
        while (avail == 0) {
            DEBUG('c', "Thread %d waiting for avail...\n", which);
            AvailCondition.Wait(&ConditionLock);
            ASSERT(ConditionLock.isHeldByCurrentThread());
            if (avail == 0) {
                DEBUG('c', "Thread %d having to wait again\n", which);
            }
        }
        DEBUG('c', "Thread %d subtracting one from %d\n", which, avail);
        ASSERT(avail > 0);
        avail--;
        ConditionLock.Release();
        currentThread->Yield();

        DEBUG('c', "Thread %d processing\n", which);

        ConditionLock.Acquire();
        avail++;
        DEBUG('c', "Thread %d adding one to %d\n", which, avail);
        AvailCondition.Broadcast(&ConditionLock);
        ConditionLock.Release();
        currentThread->Yield();
    }
    DEBUG('c', "Thread %d is done\n", which);
}
#endif

void
SimpleThread(int which)
{
    int num, val;

    for(num = 0; num < 5; num++) {
#ifdef HW1_SEMAPHORES
        VarSemaphore.P();
#elif defined(HW1_LOCKS)
        VarLock.Acquire();
#endif
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        currentThread->Yield();
        SharedVariable = val+1;
        DEBUG('w', "*** thread %d writes value %d\n", which, val+1);
#ifdef HW1_SEMAPHORES
        VarSemaphore.V();
#elif defined(HW1_LOCKS)
        VarLock.Release();
#endif
        currentThread->Yield();
    }

#ifdef HW1_SEMAPHORES
    FinishedSemaphore.P();
    finished--;
    FinishedSemaphore.V();
    int temp = 1;
    while (temp > 0) {
        FinishedSemaphore.P();
        temp = finished;
        FinishedSemaphore.V();
        currentThread->Yield();
    }
#elif defined(HW1_LOCKS)
    FinishedLock.Acquire();
    finished--;
    FinishedLock.Release();
    int temp = 1;
    while (temp > 0) {
        FinishedLock.Acquire();
        temp = finished;
        FinishedLock.Release();
        currentThread->Yield();
    }
#endif

    val = SharedVariable;
    printf("Thread %d sees final value %d\n", which, val);
}
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

#ifdef CHANGED
#ifdef HW1_TASK4
double testgettimeofday(const int numloops=2e7) {
    struct timeval start, end;
    struct timeval loop, call, total;
    struct timeval temptv;
    int i;

    ASSERT(gettimeofday(&start, NULL) == 0);
    for (i = 0; i < numloops; i++) {
        int x = 10;
        ASSERT(gettimeofday(&temptv, NULL) == 0);
        x = 20;
    }
    ASSERT(gettimeofday(&end, NULL) == 0);
    call.tv_sec = end.tv_sec - start.tv_sec;
    call.tv_usec = end.tv_usec - start.tv_usec;

    ASSERT(gettimeofday(&start, NULL) == 0);
    for (i = 0; i < numloops; i++) {
        int x = 10;
        x = 20;
    }
    ASSERT(gettimeofday(&end, NULL) == 0);
    loop.tv_sec = end.tv_sec - start.tv_sec;
    loop.tv_usec = end.tv_usec - start.tv_usec;

    total.tv_sec = call.tv_sec - loop.tv_sec;
    total.tv_usec = call.tv_usec - loop.tv_usec;
    if (total.tv_usec < 0) {
        total.tv_usec += 1e6;
        total.tv_sec -= 1;
    }

    double timepercall = (double)((total.tv_sec * 1e6) + total.tv_usec) / numloops;

    printf("gettimeofday() takes %f us\n", timepercall);

    return timepercall;
}

double testyield(const int numloops=2e7) {
    struct timeval start, end;
    struct timeval loop, call, total;
    struct timeval temptv;
    int i;

    ASSERT(gettimeofday(&start, NULL) == 0);
    for (i = 0; i < numloops; i++) {
        int x = 10;
        currentThread->Yield();
        x = 20;
    }
    ASSERT(gettimeofday(&end, NULL) == 0);
    call.tv_sec = end.tv_sec - start.tv_sec;
    call.tv_usec = end.tv_usec - start.tv_usec;

    ASSERT(gettimeofday(&start, NULL) == 0);
    for (i = 0; i < numloops; i++) {
        int x = 10;
        x = 20;
    }
    ASSERT(gettimeofday(&end, NULL) == 0);
    loop.tv_sec = end.tv_sec - start.tv_sec;
    loop.tv_usec = end.tv_usec - start.tv_usec;

    total.tv_sec = call.tv_sec - loop.tv_sec;
    total.tv_usec = call.tv_usec - loop.tv_usec;
    if (total.tv_usec < 0) {
        total.tv_usec += 1e6;
        total.tv_sec -= 1;
    }

    double timepercall = (double)((total.tv_sec * 1e6) + total.tv_usec) / numloops;

    printf("Yield() takes %f us\n", timepercall);

    return timepercall;
}

void TimeLoopThread(int threads) {
    int numloops=1e3;
    //int blocksize=4 * 1024;
    //int blocksize=256 * 1024;
    int blocksize=8 * 1024 * 1024;

    struct timeval start, end;
    struct timeval total;
    int i, j;

    ASSERT(threads >= 1);

    char *data = new char[blocksize];
    char *data2;
    if (threads == 1) {
        data2 = new char[blocksize];
    }

    for (i = 0; i < blocksize; i++) {
        data[blocksize] = 0;
    }
    if (threads == 1) {
        for (i = 0; i < blocksize; i++) {
            data[blocksize] = 0;
        }
    }

    printf("Finished generating data\n");

    currentThread->Yield();

    ASSERT(gettimeofday(&start, NULL) == 0);
    if (threads != 1) {
        for (i = 0; i < numloops; i++) {
            for (j = 0; j < blocksize; j++) {
                char temp = data[blocksize];
                if (j % 1024 == 1023) {
                    currentThread->Yield();
                }
            }
        }
    } else {
        char *garbage = data;
        for (i = 0; i < numloops; i++) {
            for (j = 0; j < blocksize * 2; j++) {
                char temp = data[blocksize];
                if (j % 1024 == 1023) {
                    currentThread->Yield();
                    if (garbage == data) {
                        garbage == data2;
                    } else {
                        garbage == data;
                    }
                }
            }
        }
    }
    ASSERT(gettimeofday(&end, NULL) == 0);

    delete data;

    total.tv_sec = end.tv_sec - start.tv_sec;
    total.tv_usec = end.tv_usec - start.tv_usec;
    if (total.tv_usec < 0) {
        total.tv_usec += 1e6;
        total.tv_sec -= 1;
    }

    double timeperloop = (double)((total.tv_sec * 1e6) + total.tv_usec) / numloops;

    printf("Each loop iteration takes %f us\n", timeperloop);
}

void Task4(int n) {
    switch (n) {
        case 1:
            printf("*** determining gettimeofday() call time\n");
            testgettimeofday();
            break;
        case 2:
            printf("*** determining Yield() call time\n");
            testyield();
            break;
        case 3:
            TimeLoopThread(1);
            break;
        case 4: {
            Thread *t = new Thread("blarg");
            t->Fork(TimeLoopThread, 2);
            TimeLoopThread(2);
            break;
        }
        default:
            printf("Task4: unknown test %d\n", n);
            break;
    }
}
#endif


//----------------------------------------------------------------------
// ThreadTestN
// 	Set up a ping-pong between N+1 threads, by forking a thread
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTestN(int n)
{
    char threadnames[n][11];
    DEBUG('t', "Entering ThreadTestN with %d\n", n);

#if defined(HW1_SEMAPHORES) || defined(HW1_LOCKS)
    finished = n + 1;
#elif defined(HW1_CONDITION)
    avail = 3;
#endif

    for (int i = 0; i < n; i++) {
        snprintf(threadnames[i], 11, "thread %d", i);
        Thread *t = new Thread(strdup(threadnames[i]));
#ifdef HW1_CONDITION
        t->Fork(ConditionThread, i + 1);
#else
        t->Fork(SimpleThread, i + 1);
#endif
    }
#ifdef HW1_CONDITION
    ConditionThread(0);
#else
    SimpleThread(0);
#endif
}
#else
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
#endif

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

#ifdef CHANGED
void
ThreadTest(int n)
{
#ifdef HW1_TASK4
    Task4(n);
#else
    ThreadTestN(n);
#endif
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

