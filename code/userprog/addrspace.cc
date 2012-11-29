// addrspace.cc 
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option 
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#ifdef HOST_SPARC
#include <strings.h>
#endif

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the 
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void 
SwapHeader (NoffHeader *noffH)
{
	noffH->noffMagic = WordToHost(noffH->noffMagic);
	noffH->code.size = WordToHost(noffH->code.size);
	noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
	noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
	noffH->initData.size = WordToHost(noffH->initData.size);
	noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
	noffH->uninitData.size = WordToHost(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
	noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

int AddrSpace::Init(const AddrSpace *space) {
    DEBUG('2', "Copying AddrSpace %p with %d pages\n", space, space->numPages);

    pcb = NULL;

    numPages = space->numPages;

    if (numPages > memmanager->getFreePages()) {
        DEBUG('s', "Not enough free pages to create address space\n");
        return 1;
    }

    pageTable = new TranslationEntry[numPages];
    for (int i = 0; i < numPages; i++) {
        memcpy(&pageTable[i], &(space->pageTable[i]), sizeof(TranslationEntry));
        int page = memmanager->getPage();
#ifndef VM
        ASSERT(page != -1);
#endif
        pageTable[i].physicalPage = page; // Note: with VM this doesn't do anything because inMem is set to false below.
#ifdef VM
	// Copy parent page.
	pageTable[i].inMem = FALSE;
	pageTable[i].firstUse = FALSE;
	pageTable[i].swapSector = memmanager->getSector();
	memmanager->clonePage(&pageTable[i], &(space->pageTable[i]));
#else
        memcpy(machine->mainMemory + (page * PageSize), 
	       machine->mainMemory + (space->pageTable[i].physicalPage * PageSize), PageSize);
#endif
    }
    return 0;
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	First, set up the translation from program memory to physical 
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------
int AddrSpace::Init(OpenFile *executable)
{
    pcb = NULL;

    NoffHeader noffH;
    unsigned int i, size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && 
		(WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);
    if (noffH.noffMagic != NOFFMAGIC) {
        DEBUG('s', "NOFF magic is wrong\n");
        return 1;
    }

// how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size 
			+ UserStackSize;	// we need to increase the size
						// to leave room for the stack
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;

    // check we're not trying to run anything too big -- at least until we have virtual memory
    if (numPages > memmanager->getFreePages()) {
        DEBUG('s', "Not enough free pages to create address space\n");
        return 1;
    }

    DEBUG('a', "Initializing address space, num pages %d, size %d\n", 
					numPages, size);
// first, set up the translation 
    pageTable = new TranslationEntry[numPages];
    for (i = 0; i < numPages; i++) {
        int page = memmanager->getPage();
#ifndef VM
        ASSERT(page != -1);
#endif
	pageTable[i].virtualPage = i;
	pageTable[i].physicalPage = page;
	pageTable[i].valid = TRUE;
	pageTable[i].use = FALSE;
	pageTable[i].dirty = FALSE;
	pageTable[i].readOnly = FALSE;  // if the code segment was entirely on 
					// a separate page, we could set its 
					// pages to be read-only
#ifdef VM
	pageTable[i].inMem = FALSE;
	pageTable[i].swapSector = memmanager->getSector();
	pageTable[i].firstUse = TRUE;
#endif
	// With VM, pages aren't in memory yet.
#ifndef VM	
	memset(machine->mainMemory + (page * PageSize), '0', PageSize);
#endif
    }
    
// zero out the entire address space, to zero the unitialized data segment 
// and the stack segment
    //bzero(machine->mainMemory, size);

// then, copy in the code and data segments into memory
    if (noffH.code.size > 0) {
        DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", 
			noffH.code.virtualAddr, noffH.code.size);
        int ret = ReadFile(noffH.code.virtualAddr, executable, noffH.code.size, noffH.code.inFileAddr);
        if (ret != 0) {
            DEBUG('s', "Unable to read code from NOFF\n");
            return 1;
        }
    }
    if (noffH.initData.size > 0) {
        DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", 
			noffH.initData.virtualAddr, noffH.initData.size);
        int ret = ReadFile(noffH.initData.virtualAddr, executable, noffH.initData.size, noffH.initData.inFileAddr);
        if (ret != 0) {
            DEBUG('s', "Unable to read data from NOFF\n");
            return 1;
        }
    }

    DEBUG('2', "Loaded Program: %d code | %d data | %d bss (%d pages)\n", noffH.code.size, noffH.initData.size, noffH.uninitData.size, numPages);

    return 0;
}

// note: pages are /always/ aligned to PageSize
int AddrSpace::ReadFile(int virtAddr, OpenFile* file, int size, int fileAddr) {
    int paddr, vaddr, faddr;
    int remaining = size;

    DEBUG('a', "ReadFile %d from %08x to %08x\n", size, fileAddr, virtAddr);

    vaddr = virtAddr;
    faddr = fileAddr;
    while (remaining) {
        int toread = PageSize - (vaddr % PageSize);
        if (toread > remaining) {
            toread = remaining;
        }

        if (!Translate(vaddr, &paddr, TRUE)) {
            DEBUG('s', "Unable to translate address %08x\n", vaddr);
            return 1;
        }

        int ret = file->ReadAt(diskBuffer, toread, faddr);
        if (ret != toread) {
            DEBUG('s', "Unable to read proper amount of stuff from file\n");
            return 1;
        }

        memcpy(machine->mainMemory + paddr, diskBuffer, toread);

        remaining -= toread;
        vaddr += toread;
        faddr += toread;
    }

    return 0;
}

void AddrSpace::InitPCB(AddrSpace *parentspace, Thread *thread) {
    PCB *temp = NULL;
    if (parentspace) {
        temp = parentspace->pcb;
    }

    pcb = psmanager->GetNewPCB(temp, thread);
}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{

    if (pageTable) {
        for (int i = 0; i < numPages; i++) {
#ifdef VM
            memmanager->clearPage(&pageTable[i]);
	    // Invalidate TLB.
	    for (int i = 0; i < TLBSize; i++) {
	      TranslationEntry *tlbEntry = &(machine->tlb[i]);
	      tlbEntry->valid = 0;
	    }

#else
            memmanager->clearPage(pageTable[i].physicalPage);
#endif
        }
    }
    delete[] pageTable;
}

bool AddrSpace::Translate(int vaddr, int *paddr, bool writing) {
    if (!paddr) {
        return false;
    }

    TranslationEntry *entry = NULL;
    int i;

    int vpage = vaddr / PageSize;
    int voffset = vaddr % PageSize;

    for (i = 0; i < numPages; i++) {
        if (pageTable[i].valid && pageTable[i].virtualPage == vpage) {
            entry = &pageTable[i];
            break;
        }
    }

    if (entry == NULL) {
        DEBUG('s', "Unable to find virtual address %08x in xlate\n", vaddr);
        return false;
    }

#ifdef VM
    if (!entry->inMem) {
      // Page fault.
      //printf("kfault\n");
      memmanager->loadPage(entry);
      //printf("entry->inMem=%d\n",entry->inMem);
    }
    if (!entry->inMem) {
      printf("Failed to load page from swap. Terminating.\n");
      ASSERT(FALSE);
    }
#endif

    entry->use = TRUE;
    if (writing) {
      entry->dirty = TRUE;
    }
    
    int ppage = entry->physicalPage;

    if (ppage >= NumPhysPages) {
        DEBUG('s', "Found page entry, but ppage was too big (%x)\n", ppage);
        return false;
    }

    *paddr = ppage * PageSize + voffset;

    DEBUG('a', "Translated %08x into %08x\n", vaddr, *paddr);

    return true;
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
AddrSpace::InitRegisters()
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);	

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void AddrSpace::SaveState() 
{

#ifdef USE_TLB
  //  printf("savestate %p\n", this);
    // Invalidate TLB.
    for (int i = 0; i < TLBSize; i++) {
      TranslationEntry *tlbEntry = &(machine->tlb[i]);
      for (int j = 0; j < numPages; j++) {
	TranslationEntry *addrspaceEntry = &(pageTable[j]);
	if (tlbEntry->valid && addrspaceEntry->valid && tlbEntry->virtualPage == addrspaceEntry->virtualPage) {
	  ASSERT(tlbEntry->use);
	  addrspaceEntry->dirty = tlbEntry->dirty;
	  addrspaceEntry->use = tlbEntry->use;
	}
      }
      tlbEntry->valid = 0;

    }
#endif

}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState() 
{
#ifndef USE_TLB
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;
#else
    //    printf("restorestate %p\n", this);
    // Invalidate TLB.
    for (int i = 0; i < TLBSize; i++) {
      TranslationEntry *tlbEntry = &(machine->tlb[i]);
      tlbEntry->valid = 0;
    }
#endif

}
