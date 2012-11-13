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
#include "time.h"

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

#ifdef CHANGED

#ifdef HW1_LOCKS
int SharedVariable;
Lock control("SharedVariable control");
Lock barrier("Barrier control");
int numRemainingThreads = 0; // busy wait each thread until this is finished

void SimpleThread(int which) {

    DEBUG('t', "SimpleThread running with locks controlling access.\n");
    int num, val; 

    for(num = 0; num < 5; num++) { 
        control.Acquire();
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        SharedVariable = val+1;
        control.Release();
        currentThread->Yield(); 
    } 

    barrier.Acquire();
    numRemainingThreads--;
    barrier.Release();

    while (numRemainingThreads > 0) {
        currentThread->Yield();
    }

    val = SharedVariable; 
    printf("Thread %d sees final value %d\n", which, val); 
}

#elif HW1_SEMAPHORES
int SharedVariable;
int NUM_LICENCES = 1;
Semaphore control("SharedVariable control", NUM_LICENCES);
Semaphore barrier("Barrier control", 1);

int numRemainingThreads = 0; // busy wait each thread until this is finished

void SimpleThread(int which) { 

    DEBUG('t', "SimpleThread running with semaphores controlling access.\n");
    int num, val; 

    for(num = 0; num < 5; num++) { 
        control.P();
        val = SharedVariable;
        printf("*** thread %d sees value %d\n", which, val);
        SharedVariable = val+1;
        control.V();
        currentThread->Yield(); 
    } 

    barrier.P();
    numRemainingThreads--;
    barrier.V();

    while (numRemainingThreads > 0) {
        currentThread->Yield();
    }

    val = SharedVariable; 
    printf("Thread %d sees final value %d\n", which, val); 
}

#else
int SharedVariable;

void SimpleThread(int which) { 

    DEBUG('t', "SimpleThread running with no shared variable control; default\n");
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


#ifdef HW1_LAUNDRY

int PARALLEL_MACHINE_ACCESSES = 1;
int MACHINE_FREE = 1;
int MACHINE_BUSY = 0;
const int NMACHINES = 2;
int available[NMACHINES];

#ifdef HW1_LOCKS // FIX LAUNDRY WITH LOCKS/COND

Condition* availableMachine = new Condition("Available machines");
Lock* controlCond = new Lock("Controlling condition variable");
Lock* machineHandler = new Lock("Machine handler");

int allocate(int personID) /* Returns index of available machine */ {

    DEBUG('l', "Trying to allocate a machine to person %d\n", personID);
    int i;
    bool machineAcquired = false;

    while (!machineAcquired) {

        /* Try to acquire a washing machine */
        machineHandler->Acquire();
        DEBUG('l', "Machine handler acquried for person %d\n", personID);
        int machineNum = 0;
        for (machineNum = 0; machineNum < NMACHINES; machineNum++) {

            if (available[machineNum] == MACHINE_FREE) {
                available[machineNum] = MACHINE_BUSY;
                machineHandler->Release();
                machineAcquired = true;
                break;
            }
        }

        if (machineAcquired) {
            DEBUG('l', "Machine %d allocated to person %d\n", machineNum, personID);
            return machineNum;
        } else {
            DEBUG('l', "Person %d could not be allocated a machine.  Sleeping.\n", personID);
            machineHandler->Release();
            controlCond->Acquire();
            availableMachine->Wait(controlCond);
            controlCond->Release();
        }
    }
}

void release(int machineNum) {
    
    /* Mark machine as free */
    machineHandler->Acquire();
    available[machineNum] = MACHINE_FREE;
    machineHandler->Release();
    DEBUG('l', "Machine %d successfully released\n", machineNum);

    /* Let the people waiting know the machine is free */
    DEBUG('l', "Letting people know machine %d is free\n", machineNum);
    controlCond->Acquire();
    availableMachine->Broadcast(controlCond);
    controlCond->Release();
}

#elif HW1_SEMAPHORES // FIX LAUNDRY WITH SEMAPHORES

Semaphore* availableMachines = new Semaphore("Available machines", NMACHINES);
Semaphore* machineHandler = new Semaphore("Machines", PARALLEL_MACHINE_ACCESSES);

int allocate(int personID) /* Returns index of available machine */ {

    DEBUG('l', "Semap NACHOS impl: Trying to allocate a machine to person %d\n", personID);
    availableMachines->P();
    machineHandler->P();

    DEBUG('l', "Semap impl: Allocating a machine to a person\n");
    while (1) { // account for two machines wanting the same one.
        int i;
        for (i = 0; i < NMACHINES; i++) {
            if (available[i] == MACHINE_FREE) {
                available[i] = MACHINE_BUSY;
                DEBUG('l', "Semap NACHOS impl: Allocating %d to person %d\n", i, personID);
                machineHandler->V();
                return i;
            }
        }
    }
}

void release(int machine) { /* Release machine */

    machineHandler->P();
    DEBUG('l', "Semaphores impl: Releasing machine %d for usage\n", machine);
    available[machine] = MACHINE_FREE;
    machineHandler->V();
    availableMachines->V();
}

#else // USE DEFAULT LAUNDRY CODE

Semaphore* availableMachines = new Semaphore("Available machines", NMACHINES);

int allocate(int personID) /* Returns index of available machine */ { 
    DEBUG('l', "Default NACHOS impl: Trying to allocate a machine to person %d\n", personID);
    int i; 
    availableMachines->P();
    for (i=0; i < NMACHINES; i++) {
        if (available[i] == MACHINE_FREE) { 
            available[i] = MACHINE_BUSY; 
            DEBUG('l', "Default NACHOS impl: Allocating %d to person %d\n", i, personID);
            return i; 
        } 
    }
} 

void release(int machine) /* Release machine */ { 
    DEBUG('l', "Default NACHOS impl: Releasing a machine\n");
    available[machine] = MACHINE_FREE; 
    availableMachines->V();
}

#endif // Choice b/w how to sync laundry code

void doLaundry(int personID) { /* A single person doing a single load */

    DEBUG('l', "Person %d is attempting to get a machine\n", personID);
    time_t startLaundryTime;
    int machine = allocate(personID);
    startLaundryTime = time(NULL); // get current time
    DEBUG('l', "Person %d is doing laundry\n", personID);
    while (difftime(time(NULL),startLaundryTime) < 3) { // wait while doing laundry
        currentThread->Yield();
    }
    DEBUG('l', "Person %d is done with laundry and is releasing the machine\n", personID);
    release(machine);
}

void setAllMachinesToFree() {

    DEBUG('l', "Setting all machines to free\n");
    int i = 0;
    for (i = 0; i < NMACHINES; i++) {
        available[i] = MACHINE_FREE;
    }
}

void openLaundromat(int numCustomers) { /* Num of machines is a defined variable */

    numCustomers = numCustomers > 0 ? numCustomers : 5; // default to 5 customers
    DEBUG('l', "Num customers: %d\n", numCustomers);
    DEBUG('l', "Num machines: %d\n", NMACHINES);

    DEBUG('l', "Opening laundromat for business\n");
    setAllMachinesToFree();
    int i;
    Thread* t;
    for (i = 0; i < numCustomers; i++) {
        DEBUG('l', "Forking a new person to do laundry\n");
        t = new Thread("person");
        t->Fork(doLaundry, i);
    }
}

#endif // All of laundry code

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1(int n)
{
    DEBUG('t', "Entering ThreadTest1\n");

#ifdef HW1_LOCKS
    DEBUG('t', "Using locks\n");
#elif HW1_SEMAPHORES
    DEBUG('t', "Using semaphores\n");
#else
    DEBUG('t', "Not using semaphores or locks\n");
#endif
    
    int i = 0;
    Thread* t = NULL;
    for (i = 1; i <= n; i++) {
        DEBUG('t', "Making and forking thread #%d\n", i);
        t = new Thread("forked thread");
        t->Fork(SimpleThread, i);
    }

    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest(int n)
{
    if (n < 0) {
        printf("Setting argument -q to 4.  You can't specify a negative num");
        n = 4;
    }
    //numRemainingThreads = n + 1;

    ThreadTest1(n);
}

#else // Use the default nachos code

//----------------------------------------------------------------------
// SimpleThread
//      Loop 5 times, yielding the CPU to another ready thread 
//      each iteration.
//
//      "which" is simply a number identifying the thread, for debugging
//      purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
        printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest1
//      Set up a ping-pong between two threads, by forking a thread 
//      to call SimpleThread, and then calling SimpleThread ourselves.
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
//      Invoke a test routine.
//----------------------------------------------------------------------

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

#endif // CHANGED
