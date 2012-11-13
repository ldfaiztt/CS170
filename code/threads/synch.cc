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

// Constants for Lock
const int LOCK_BUSY = 0;
const int LOCK_FREE = 1;

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(char* debugName, int initialValue) {

    name = debugName;
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore() {

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

void Semaphore::P() {

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

void Semaphore::V() {

    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
        scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}

#ifdef CHANGED

//----------------------------------------------------------------------
// Lock::Lock
//      Initialize a lock, so that it can be used for synchronization.
//
//      "debugName" is an arbitrary name, useful for debugging.
//----------------------------------------------------------------------

Lock::Lock(char* debugName) {

    name = debugName;
    value = LOCK_FREE;
    queue = new List;
}

//----------------------------------------------------------------------
// Lock::~Lock
//      De-allocate lock, when no longer needed.
//----------------------------------------------------------------------

Lock::~Lock() {

    delete queue;
}

//----------------------------------------------------------------------
// Lock::Acquire
//     Wait until lock value > 0, then decrement.  Checking the value
//     and decrementing must be done atomically, so we need to disable
//     interrupts before checking the value.
//
//     Note that Thread::Sleep assumes that interrupts are disabled
//     when it is called.
//----------------------------------------------------------------------

void Lock::Acquire() {

    DEBUG('t', "Current thread %x: Acquiring lock\n", currentThread);
    IntStatus oldLevel = interrupt->SetLevel(IntOff); // disable interrupts

    while (value == LOCK_BUSY) {
        queue->Append((void*)currentThread);
        currentThread->Sleep();
    }
    value = LOCK_BUSY;
    lockingThread = currentThread;

    (void) interrupt->SetLevel(oldLevel); // re-enable interrupts
}


//----------------------------------------------------------------------
// Lock::Release
//    Release the lock for use by other threads. Just like Acquire, this
//    operation has to be atomic, so we disable interrupts during the
//    execution.  Scheduler::ReadyToRun() assumes that threads are
//    disabled when it is called.
//----------------------------------------------------------------------

void Lock::Release() {

    if (isHeldByCurrentThread()) {

        DEBUG('t', "Current thread %x: Releasing lock\n", currentThread);
        Thread* thread;
        IntStatus oldLevel = interrupt->SetLevel(IntOff);

        thread = (Thread*)queue->Remove();
        if (thread != NULL) {
            scheduler->ReadyToRun(thread);
        }
        value = LOCK_FREE;
        (void) interrupt->SetLevel(oldLevel);
    }
}

//----------------------------------------------------------------------
// Lock::isHeldByCurrentThread
//     Checks to see if the current thread is the one who owns this lock.
//     Useful for determining ability to release a lock.
//----------------------------------------------------------------------

bool Lock::isHeldByCurrentThread() {

    return (currentThread == lockingThread);
}

//----------------------------------------------------------------------
// Condition::Condition
//     Initializes a condition variable; debugName is arbitrary.
//----------------------------------------------------------------------

Condition::Condition(char* debugName) {

    name = debugName;
    queue = new List;
}

//----------------------------------------------------------------------
// Condition::~Condition
//     De-allocates queue memory when object is deleted.
//----------------------------------------------------------------------

Condition::~Condition() {

    delete queue;
}

//----------------------------------------------------------------------
// Condition::Wait
//     Waits for this condition to become free and then acquires it for the
//     current thread.
//
//     Note: This operation has to be atomic, so we disable interrupts for the
//     execution of this method.
//----------------------------------------------------------------------

void Condition::Wait(Lock* conditionLock) {

    if (conditionLock->isHeldByCurrentThread()) {

        IntStatus oldLevel = interrupt->SetLevel(IntOff); // disable interrupts

        queue->Append((void*)currentThread);
        conditionLock->Release();
        currentThread->Sleep();

        (void) interrupt->SetLevel(oldLevel); // re-enable interrupts
        conditionLock->Acquire();
    }
}

//----------------------------------------------------------------------
// Condition::Signal
//     Wakes up one of the threads that is waiting on this condition.
//----------------------------------------------------------------------

void Condition::Signal(Lock* conditionLock) {

    if (conditionLock->isHeldByCurrentThread()) {

        IntStatus oldLevel = interrupt->SetLevel(IntOff); // disable interrupts

        Thread* thread;
        thread = (Thread*)queue->Remove();
        if (thread != NULL) {
            scheduler->ReadyToRun(thread);
        } else {
            DEBUG('t', "no more threads are waiting on this condition.");
        }

        (void) interrupt->SetLevel(oldLevel); // re-enable interrupts
    }
}

//----------------------------------------------------------------------
// Condition::Broadcast
//     Wakes up all threads that are waiting on this condition.
//----------------------------------------------------------------------

void Condition::Broadcast(Lock* conditionLock)
{
    if (conditionLock->isHeldByCurrentThread()) {

        IntStatus oldLevel = interrupt->SetLevel(IntOff); // disable interrupts

        Thread* thread;
        bool moreWaitingThreads = true;

        while (moreWaitingThreads) {

            thread = (Thread*)queue->Remove();

            if (thread != NULL) {
                scheduler->ReadyToRun(thread);
            } else {
                DEBUG('t', "No more threads are waiting on this condition.\n");
                moreWaitingThreads = false;
            }
        }

        (void) interrupt->SetLevel(oldLevel); // re-enable interrupts
    }
}

#else

Lock::Lock(char* debugName) {}
Lock::~Lock() {}
void Lock::Acquire() {}
void Lock::Release(){}

Condition::Condition(char* debugName) { }
Condition::~Condition() { }
void Condition::Wait(Lock* conditionLock) { ASSERT(FALSE); }
void Condition::Signal(Lock* conditionLock) { }
void Condition::Broadcast(Lock* conditionLock) { }

#endif
