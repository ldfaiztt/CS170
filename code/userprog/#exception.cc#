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
#include "fscalls.cc"


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

inline void SYSCALL_PRINT(char *name) {
    int pid = currentThread->space->pcb->GetPID();
    DEBUG('2', "System Call: %d invoked %s\n", pid, name);
}

namespace {
// thread control syscalls
void Syscall_Halt() {
    SYSCALL_PRINT("Halt");
    DEBUG('f', "Shutdown, initiated by user program.\n");
    interrupt->Halt();
}

void Syscall_Exit(int status) {
    SYSCALL_PRINT("Exit");
    DEBUG('f', "Exit(%d);\n", status);

    PCB *temp = currentThread->space->pcb;

    DEBUG('2', "Process %d exits with %d\n", temp->GetPID(), status);
    temp->Exit(status);
    delete currentThread->space;
    currentThread->Finish();
}

void exec_dummy(int) {
    currentThread->space->InitRegisters();
    currentThread->space->RestoreState();

    machine->Run();
}

int vstrlen(char *string) {
    int paddr;
    int len = -1;

    do {
        len++;
        if (!currentThread->space->Translate(reinterpret_cast<int>(string + len), &paddr, 0)) {
            return -1;
        }
    } while (machine->mainMemory[paddr]);

    return len;
}

int copy_to_kernel(char *kernel, char *user, int len) {
    int paddr;

    for (int i = 0; i < len; i++) {
        if (!currentThread->space->Translate(reinterpret_cast<int>(user + i), &paddr, 0)) {
            return -1;
        }
        kernel[i] = machine->mainMemory[paddr];
    }

    return len;
}

char *alloc_copy_str_from_user(char *string) {
    int len = vstrlen(string);
    if (len < 0) {
        DEBUG('s', "Unable to get length of string\n");
        return NULL;
    }

    char *kstring = new char[len + 1];
    int ret = copy_to_kernel(kstring, string, len + 1);
    if (ret != len + 1) {
        DEBUG('s', "Unable to copy string into kernelland\n");
        return NULL;
    }

    return kstring;
}

SpaceId Syscall_Exec(char *name) {
    SYSCALL_PRINT("Exec");
    DEBUG('f', "Exec(%p);\n", name);

    int ret = 0;

// turn name into something useful
    char *kname = alloc_copy_str_from_user(name);
    if (kname == NULL) {
        DEBUG('s', "Unable to get string from userland\n");
        return -1;
    }

    OpenFile *executable = fileSystem->Open(kname);
    if (executable == NULL) {
        DEBUG('s', "Unable to open file %s\n", kname);
        delete[] kname;
        return -1;
    }

    AddrSpace *space = new AddrSpace();
    ret = space->Init(executable);
    delete executable;
    if (ret != 0) {
        DEBUG('s', "Unable to create new address space for %s\n", kname);
        delete space;
        delete[] kname;
        return -1;
    }

    Thread *thread = new Thread("execy");

    space->InitPCB(currentThread->space, thread);

    thread->space = space;
    thread->Fork(exec_dummy, 0);

    SpaceID pid = space->pcb->GetPID();

    DEBUG('2', "Exec Program: %d loading %s\n", pid, kname);
    delete[] kname;

    currentThread->Yield();

    return pid;
}

int Syscall_Join(SpaceId id) {
    SYSCALL_PRINT("Join");
    DEBUG('f', "Join(%d);\n", id);

    return psmanager->WaitPCB(id);
}

void fork_dummy(int func) {
    currentThread->space->InitRegisters();
    currentThread->space->RestoreState();

    machine->registers[PCReg] = func;
    machine->registers[NextPCReg] = func + 4;
    machine->registers[RetAddrReg] += 8;

    machine->Run();
}

SpaceID Syscall_Fork(void (*func)()) {
    SYSCALL_PRINT("Fork");
    DEBUG('f', "Fork(%p);\n", func);

    AddrSpace *parent, *child;

    parent = currentThread->space;
    child = new AddrSpace();
    if (child->Init(parent) != 0) {
        DEBUG('s', "Unable to fork()\n");
        delete child;
        return -1;
    }

    Thread *childthread = new Thread("forky");

    child->InitPCB(parent, childthread);

    // Copy file descriptors upon forking, so that the child process can continue to use files.
    for (int i = 0; i < parent->pcb->userOpenFileCount; i++) {
      UserOpenFile *parentFile = parent->pcb->openUserFiles[i];
      UserOpenFile *childFile = new UserOpenFile();
      char *childFileName = new char[strlen(parentFile->fileName) + 1];
      strcpy(childFileName, parentFile->fileName);
      childFile->fileName = childFileName;
      childFile->sysOpenFilePtr = parentFile->sysOpenFilePtr;
      childFile->seekPosition = parentFile->seekPosition;
      childFile->sysOpenFilePtr->openCount += 1;
      child->pcb->openUserFiles[i] = childFile;
    }
    child->pcb->userOpenFileCount = parent->pcb->userOpenFileCount;


    childthread->space = child;
    childthread->Fork(fork_dummy, reinterpret_cast<int>(func));

    SpaceID pid = child->pcb->GetPID();
    DEBUG('2', "Process %d Fork: start at address %d with %d pages memory\n", pid, reinterpret_cast<int>(func), child->numPages);

    currentThread->Yield();

    return pid;
}

void Syscall_Yield() {
    SYSCALL_PRINT("Yield");
    DEBUG('f', "Yield();\n");

    currentThread->Yield();
}

// filesystem syscalls
void Syscall_Create() {
    SYSCALL_PRINT("Create");
    scCreate(scGetStringArg(0, false));
}

void Syscall_Open() {
    SYSCALL_PRINT("Open");
    scReturnInt(scOpen(scGetStringArg(0, true)));
}

void Syscall_Write() {
    SYSCALL_PRINT("Write");
    scReturnInt(scWrite(scGetUspacePtrArg(0), scGetIntArg(1), scGetIntArg(2)));
}

int Syscall_Read() {
    SYSCALL_PRINT("Read");
    scReturnInt(scRead(scGetUspacePtrArg(0), scGetIntArg(1), scGetIntArg(2)));
}

void Syscall_Close() {
    SYSCALL_PRINT("Close");
    scClose(scGetIntArg(0));
}
};

#ifdef USE_TLB
void Sys_PageFault() {
  int vpage = machine->ReadRegister(BadVAddrReg) / PageSize;
  int ppage = 0;
  TranslationEntry *pageTable = currentThread->space->pageTable;

  // Find entry in addrspace.
  TranslationEntry *entry = NULL;
  for (int i = 0; i < currentThread->space->numPages; i++) {
    if (pageTable[i].valid && pageTable[i].virtualPage == vpage) {
      entry = &pageTable[i];
      break;
    }
  }

  if (entry != NULL) {
      if (!entry->inMem) {
	  // Page fault. Load from swap first.
	  memmanager->loadPage(entry);
  	  if (!entry->inMem) {
  	      printf("Failed to load page from swap. Terminating.\n");
	      ASSERT(FALSE);
	  }
      } else {
	  // TLB Fault. Just copy from addrspace into TLB.
      }

      ppage = entry->physicalPage;
      DEBUG('s', "Add TLB: %d -> %d\n", vpage, ppage);
      // Copy the new mapping into the TLB.
      TranslationEntry *tlbEntry = &(machine->tlb[nextTlbEntry]); // Destination TLB entry.
      if (tlbEntry->valid) {
	// Entry is about to be removed from TLB, copy changes back to its entry in addrspace.
	TranslationEntry *addrspaceEntry = NULL;
	for (int i = 0; i < currentThread->space->numPages; i++) {
	  if (pageTable[i].valid && pageTable[i].virtualPage == tlbEntry->virtualPage) {
	    addrspaceEntry = &pageTable[i];
	    break;
	  }
	}
	ASSERT(addrspaceEntry != NULL);
	ASSERT(tlbEntry->use);	
	//printf("remove %d from tlb dirty=%d\n", tlbEntry->virtualPage, tlbEntry->dirty);
	addrspaceEntry->dirty = tlbEntry->dirty;
	addrspaceEntry->use = tlbEntry->use;
      }

      tlbEntry->valid = 1;
      tlbEntry->virtualPage = vpage;
      tlbEntry->physicalPage = ppage;
      tlbEntry->use = entry->use;
      tlbEntry->dirty = entry->dirty;

      nextTlbEntry = (nextTlbEntry + 1) % TLBSize;
  } else {
      printf("Attempted to access invalid vpage %d. Terminating.\n", vpage);
      ASSERT(FALSE);
  }
}
#endif


void
ExceptionHandler(ExceptionType which)
{
    int ret;
    int type = machine->ReadRegister(2);

    if (which == SyscallException) {
        switch (type) {
            case SC_Halt:
                Syscall_Halt();
                break;
            case SC_Exit:
                Syscall_Exit(machine->ReadRegister(4));
                break;
            case SC_Exec:
                ret = Syscall_Exec((char *)machine->ReadRegister(4));
                machine->WriteRegister(2, ret);
                break;
            case SC_Join:
                ret = Syscall_Join((SpaceId)machine->ReadRegister(4));
                machine->WriteRegister(2, ret);
                break;
            case SC_Fork:
                ret = Syscall_Fork((void (*)())machine->ReadRegister(4));
                machine->WriteRegister(2, ret);
                break;
            case SC_Yield:
                Syscall_Yield();
                break;
            case SC_Create:
                Syscall_Create();
                break;
            case SC_Open:
  	        Syscall_Open();
		break;
	    case SC_Read:
                Syscall_Read();
                break;
            case SC_Write:
                Syscall_Write();
                break;
            case SC_Close:
                Syscall_Close();
                break;
            default:
                printf("Unexpected Syscall %d\n", type);
                ASSERT(FALSE);
        }
	// Advance the machine to the next instruction.
	machine->WriteRegister(PrevPCReg, machine->ReadRegister(PrevPCReg) + 4);
	machine->WriteRegister(PCReg, machine->ReadRegister(PCReg) + 4);
	machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg) + 4);
    } else if (which == PageFaultException) {
#ifdef USE_TLB
      Sys_PageFault();
      // Do not advance the machine to the next instruction.
#else
      printf("Not allowed to pagefault without a TLB!\n");
      ASSERT(FALSE);
#endif
    } else {
	printf("Unexpected user mode exception %d %d\n", which, type);
	ASSERT(FALSE);
    }
}
