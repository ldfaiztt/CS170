// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    
    while (value == 0) { 			// semaphore not available
	queue->Append((void *)currentThread);	// so go to sleep
	currentThread->Sleep();
    } 
    value--; 					// semaphore available, 
						// consume its value
    
    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}

// Dummy functions -- so we can compile our later assignments 
// Note -- without a correct implementation of Condition::Wait(), 
// the test case in the network assignment won't work!
#if defined(CHANGED)
Lock::Lock(char* debugName) 
{
	name = debugName;
	free = true;
	queue = new List;
}
Lock::~Lock() {
	delete queue;
}
void Lock::Acquire() {
	IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    	// In the case of Acquire() being called by the thread that already owns it, do nothing
    	if(isHeldByCurrentThread()){
        
	}else{
	// Otherwise, sleep until the lock can be acquired
        	while(!free) {
            		queue->Append((void *)currentThread);
            		currentThread->Sleep();
        	}

        // Successfully acquired the lock, mark as acquired (not free) and set the owning thread
        	free = false;
		//printf("Setting ThreadHolding to %d\n",currentThread);
        	threadHolding = (void *)currentThread;
	}

    (void) interrupt->SetLevel(oldLevel);
}
void Lock::Release() {
 Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    // Ensure that the thread trying to release the lock owns it, otherwise do nothing
    if(isHeldByCurrentThread()){
        // Wake up one of the threads waiting on the lock, if any exist
        thread = (Thread *)queue->Remove();
        if(thread != NULL) scheduler->ReadyToRun(thread);
        // Free the lock
        free = true;
        threadHolding = NULL;
    }

    (void) interrupt->SetLevel(oldLevel);
}

bool Lock::isHeldByCurrentThread()
{
	bool isHeld = (threadHolding == (void *)currentThread);   
	//printf("Chekcking Lock::isHeld %d = %d ?  %d \n",currentThread,threadHolding,isHeld);	
	return(isHeld);
	
}

Condition::Condition(char* debugName) {
    name = debugName;
    queue = new List;
}

Condition::~Condition() {
	delete queue;
}

void Condition::Wait(Lock* conditionLock) { 
 	IntStatus oldLevel = interrupt->SetLevel (IntOff);
	//if(conditionLock->isHeldByCurrentThread()){
		queue->Append((void *)currentThread);  		
		conditionLock->Release();
		//printf("Thread Sleeping \n");
  		currentThread->Sleep();
		//printf("Thread Awake\n");
		conditionLock->Acquire();
	//}
  interrupt->SetLevel (oldLevel);
  
}
void Condition::Signal(Lock* conditionLock) {
	//printf("Signaling\n");
	IntStatus oldLevel = interrupt->SetLevel(IntOff);
	if(conditionLock->isHeldByCurrentThread()){
        	Thread *thread;
        	thread = (Thread *)queue->Remove();
        	if(thread != NULL){
			//printf("Sending %d to ReadyToRun, sendt by %d \n", thread, currentThread);
        		scheduler->ReadyToRun(thread);
        	}else{
			//printf("Thread = null");
		}
    	
	}else{
		//printf("ConditionLock not hold by current thread\n");
	}
    (void) interrupt->SetLevel(oldLevel);
}
void Condition::Broadcast(Lock* conditionLock) { 
	IntStatus oldLevel = interrupt->SetLevel(IntOff);
    	if(conditionLock->isHeldByCurrentThread()){
        	Thread *thread;
  		while (thread != NULL) {
    			scheduler->ReadyToRun(thread);
    			thread = (Thread *)queue->Remove();
 		}
    	}
    (void) interrupt->SetLevel(oldLevel);
}

#else

Lock::Lock(char* debugName) {}
Lock::~Lock() {}
void Lock::Acquire() {}
void Lock::Release() {}

Condition::Condition(char* debugName) { }
Condition::~Condition() { }
void Condition::Wait(Lock* conditionLock) { ASSERT(FALSE); }
void Condition::Signal(Lock* conditionLock) { }
void Condition::Broadcast(Lock* conditionLock) { }

#endif
