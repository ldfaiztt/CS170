// addrspace.h 
//	Data structures to keep track of executing user programs 
//	(address spaces).
//
//	For now, we don't keep any information about address spaces.
//	The user level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "pcb.h"
#include "MemoryManager.h"

#define UserStackSize		1024 	// increase this as necessary!

class AddrSpace {
  public:
    AddrSpace(const AddrSpace* other, PCB* pcb);  // Copy constructor
    AddrSpace(OpenFile *executable, PCB* pcb);// Create an address space
    ~AddrSpace();			// De-allocate an address space

    int Translate(int virtualAddress);  // Translates a virtual to physical addr
    int ReadFile(int virtAddr, OpenFile* file, int size, int fileAddr);
    int getNumPages() {return numPages;} // returns the number of pages held

    void InitRegisters();		// Initialize user-level CPU registers,
    void SaveState();			// Save/restore address space-specific
    void RestoreState();		// info on a context switch 
    PCB* getPCB();                      // returns the associated PCB
    bool isValid();                     // means we allocated addrspace success
    TranslationEntry *pageTable;	// Assume linear page table translation
					// for now!

  private:
    unsigned int numPages;		// Number of pages in the virtual 
					// address space
    PCB* pcb;                           // associated PCB
};

#endif // ADDRSPACE_H
