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

#ifdef CHANGED
#include <assert.h>
#endif
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
Lock::Lock(char* debugName) {
#ifdef CHANGED
    name = debugName;
    held = false;
    queue = new List;
    current = NULL;
#endif
}
Lock::~Lock() {
#ifdef CHANGED
    delete queue;
#endif
}
#ifdef CHANGED
bool Lock::isHeldByCurrentThread() {
    return current == currentThread;
}
#endif
void Lock::Acquire() {
#ifdef CHANGED
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    while (held) {
        queue->Append((void*)currentThread);
        currentThread->Sleep();
    }

    held = true;
    current = currentThread;

    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
#endif
}
void Lock::Release() {
#ifdef CHANGED
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    assert(held);
    assert(isHeldByCurrentThread());

    thread = (Thread*)queue->Remove();
    if (thread != NULL) {
        scheduler->ReadyToRun(thread);
    }

    held = false;
    current = NULL;

    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
#endif
}

Condition::Condition(char* debugName) {
#ifdef CHANGED
    queue = new List;
    lock = NULL;
#endif
}
Condition::~Condition() {
#ifdef CHANGED
    delete queue;
    // lock is handled by creating code
#endif
}
void Condition::Wait(Lock* conditionLock) {
#ifdef CHANGED
    if (lock == NULL) {
        lock = conditionLock;
    }
    assert(lock == conditionLock);
    assert(lock->isHeldByCurrentThread());

    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    queue->Append((void*)currentThread);
    lock->Release();

    currentThread->Sleep();

    lock->Acquire();

    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
#else
ASSERT(FALSE);
#endif
}
void Condition::Signal(Lock* conditionLock) {
#ifdef CHANGED
    if (lock == NULL) {
        lock = conditionLock;
    }
    assert(lock == conditionLock);
    assert(lock->isHeldByCurrentThread());

    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    thread = (Thread*)queue->Remove();
    if (thread != NULL) {
        scheduler->ReadyToRun(thread);
    }

    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
#endif
}
void Condition::Broadcast(Lock* conditionLock) {
#ifdef CHANGED
    if (lock == NULL) {
        lock = conditionLock;
    }
    assert(lock == conditionLock);
    assert(lock->isHeldByCurrentThread());

    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    while ((thread = (Thread*)queue->Remove()) != NULL) {
        scheduler->ReadyToRun(thread);
    }

    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
#endif
}
