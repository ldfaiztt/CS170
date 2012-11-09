// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include "nachossyscalls.h"


//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

#ifndef CHANGED
void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);

    if ((which == SyscallException) && (type == SC_Halt)) {
	DEBUG('a', "Shutdown, initiated by user program.\n");
   	interrupt->Halt();
    } else {
	printf("Unexpected user mode exception %d %d\n", which, type);
	ASSERT(FALSE);
    }
}
#else
// Advance the PC counters each by one step.  Probably used directly after a system call
void AdvancePCCounters()
{
	int counter = machine->ReadRegister(PCReg); 
	machine->WriteRegister(PrevPCReg,counter); 
	counter = counter + 4;
	machine->WriteRegister(PCReg,counter); 
	counter = counter + 4; 
	machine->WriteRegister(NextPCReg,counter);
}

void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);
    if ((which == SyscallException) ) {
        switch (type)
        {
        case SC_Halt: 
			{
				printf("System Call: [%d] invoked [Halt]\n", processManager->findPIDByThread(currentThread));
		        DEBUG('a', "Shutdown, initiated by user program.\n");
		        interrupt->Halt();
		        break;
            }
        case SC_Join: 
			{
				printf("System Call: [%d] invoked [Join]\n", processManager->findPIDByThread(currentThread));
				int waitOnPID = machine->ReadRegister(4);
				int result = Join(waitOnPID);
				machine->WriteRegister(2, result);
				break;
        	}
		case SC_Exit:
			{
				printf("System Call: [%d] invoked [Exit]\n", processManager->findPIDByThread(currentThread));
				int status = machine->ReadRegister(4);
				SysCallExit(status);			
				break;
			}
		case SC_Fork: 
			{
				printf("System Call: [%d] invoked [Fork]\n", processManager->findPIDByThread(currentThread));
				void (*func)() = NULL;
				func = ( void(*)() ) machine->ReadRegister(4);
				Fork(func);
				Yield();
				break;
			}
		case SC_Yield:
			{
				printf("System Call: [%d] invoked [Yield]\n", processManager->findPIDByThread(currentThread));
				Yield();
				break;
			}
		case SC_Exec:
			{
				printf("System Call: [%d] invoked [Exec]\n", processManager->findPIDByThread(currentThread));
				int fileNameAddress = machine->ReadRegister(4);
				int childPID = Exec(fileNameAddress);
				// If the execution was successful, Yield to the child process
				if(childPID >= 0)
					Yield();
				// Write the return result
				machine->WriteRegister(2, childPID);			
				break;
			}
		case SC_Create:
			{
				printf("System Call: [%d] invoked [Create]\n", processManager->findPIDByThread(currentThread));
				int fileNameAddress = machine->ReadRegister(4);
				Create(fileNameAddress);
				break;
			}
		case SC_Open:
			{
				printf("System Call: [%d] invoked [Open]\n", processManager->findPIDByThread(currentThread));
				int fileNameAddress = machine->ReadRegister(4);
				int openFileID = Open(fileNameAddress);
				machine->WriteRegister(2, openFileID);
				break;
			}
		case SC_Write:
			{
				printf("System Call: [%d] invoked [Write]\n", processManager->findPIDByThread(currentThread));
				int bufferLoc = machine->ReadRegister(4);
				int size = machine->ReadRegister(5);
				int openFileID = machine->ReadRegister(6);
				myWrite(bufferLoc, size, openFileID);
				break;
			}
		case SC_Read:
			{
				printf("System Call: [%d] invoked [Read]\n", processManager->findPIDByThread(currentThread));
				int bufferLoc = machine->ReadRegister(4);
				int size = machine->ReadRegister(5);
				int openFileID = machine->ReadRegister(6);
				int numRead = myRead(bufferLoc, size, openFileID);
				machine->WriteRegister(2, numRead);
				break;
			}
		case SC_Close:
			{
				printf("System Call: [%d] invoked [Close]\n", processManager->findPIDByThread(currentThread));
				int openFileID = machine->ReadRegister(4);
				myClose(openFileID);
				break;
			}

		}
		AdvancePCCounters();
	// Else - Not a system call
    } 
	else if( which == PageFaultException )
	{
		int vaddr;
		vaddr = machine->ReadRegister(BadVAddrReg);
		processManager->handlePageFault(vaddr);
	}
	else
	{
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(FALSE);
    }

}


#endif
