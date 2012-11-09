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
#include "syscall.h"
#include "console.h"
#include "nachossyscalls.h"
#include <limits.h>
#ifdef HOST_SPARC
#include <strings.h>
#include <stdio.h>
#include "system.h"
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

AddrSpace::AddrSpace(OpenFile *executable, int pid)
{
	// Set this to false until the constructor finishes without error
	createdSuccessfully = false;
    NoffHeader noffH;

	this->pid = pid;

    unsigned int size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && 
		(WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);


	// how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size 
			+ UserStackSize;	// we need to increase the size
						// to leave room for the stack
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;

    DEBUG('a', "Initializing address space, num pages %d, size %d\n", 
					numPages, size);
	

	/************ Page translation ******************/
	// Attempts to allocate 'numPages' physical pages
	bool success = allocatePages();
	if(!success)
	{
		createdSuccessfully = false;
		return;
	} 

	this->noffH = noffH;
	createdSuccessfully = true;
	writeExecToSwapFile(executable);
	printf("Loaded Program: [%d] code | [%d] data | [%d] bss\n", noffH.code.size, noffH.initData.size, noffH.uninitData.size);
}



//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{
	// Release all of the allocated physical pages
	cleanUp();

    delete [] pageTable;
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
	{
		registers[i] = 0;
	}

    // Initial program counter -- must be location of "Start"
	registers[PCReg] = 0;

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
	registers[NextPCReg] = 4;

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
	registers[StackReg] = (numPages * PageSize - 16);
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
	for(int i=0; i<NumTotalRegs; i++)
		registers[i] = machine->ReadRegister(i);
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
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;

	for(int i=0; i<NumTotalRegs; i++)
		machine->WriteRegister(i, registers[i]);
}

MemoryManager* AddrSpace::getMemoryManager()
{
	static MemoryManager *memoryManager;
	if(memoryManager == NULL)
		memoryManager = new MemoryManager();
	return memoryManager;
}

int AddrSpace::getPagesRequired()
{
	return numPages;
}

bool AddrSpace::isCreated()
{
	return createdSuccessfully;
}

// Free all allocated pages and mark all pages as invalid
void AddrSpace::cleanUp()
{
	MemoryManager *memoryManager = getMemoryManager();
	for(unsigned int i=0; i<numPages; i++)
	{
		if(pageTable[i].swapPage != -1)
		{
			// Free the allocated page
			int physicalPage;
			if(pageTable[i].valid)
				physicalPage = pageTable[i].physicalPage;
			else
				physicalPage= -1;
			memoryManager->releasePage(pageTable[i].swapPage, physicalPage);
			pageTable[i].swapPage = -1;
		}
	}
}

AddrSpace* AddrSpace::duplicate(int pid)
{
	MemoryManager *memoryManager = getMemoryManager();
	AddrSpace *duplicateSpace = new AddrSpace(pid);
	// The new address space will require just as many pages
	duplicateSpace->numPages = numPages;


	// Allocate pages
	bool success = duplicateSpace->allocatePages();
	if(!success)
	{
		delete duplicateSpace;		
		return NULL;
	}


	// Copy the data from the original space into the new one
	for(int i=0; i<numPages; i++)
	{
		if(pageTable[i].valid)
		{ 	// Page IS in memory, so copy from mem to swap
			int pAddr = pageTable[i].physicalPage*PageSize;
			memoryManager->writeBufferToSwapPage(&(machine->mainMemory[pAddr]), duplicateSpace->pageTable[i].swapPage);
		}
		else
		{	// Page is not in memory, copy directly from swap
			memoryManager->copyPageFromSwap(pageTable[i].swapPage, duplicateSpace->pageTable[i].swapPage);
		}


	}
	
	// Copy all of the registers between the address spaces
	for(int i=0; i<NumTotalRegs; i++)
	{
		duplicateSpace->registers[i] = this->registers[i];
	}

	return duplicateSpace;
}

bool AddrSpace::allocatePages()
{
	// Get the static (one and only one) memory manager class
	MemoryManager *memoryManager = getMemoryManager();
 
	// Allocate each virtual page a physical page (frame) in memory
    pageTable = new TranslationEntry[numPages];
	
	/*
	Initially mark as pages as having the dummy swap page index -1.
	If allocation fails, all pages will index -1 will not be released, because they
		were not allocated in the first place.
	*/
	for(unsigned int i = 0; i<numPages; i++)
		pageTable[i].swapPage = -1;

    for (unsigned int i = 0; i < numPages; i++)
	{
		pageTable[i].virtualPage = i;

		int freeSwapPage = memoryManager->allocateSwapPage();
		printf("Z [%d]: [%d] \n", pid, i);

		// Ensure allocation succeeded ... else take note of the failure and cleanup
		if(freeSwapPage == MM_ALLOCATION_FAILED)
		{
			DEBUG('a', "Page Allocation Failed\n");
			cleanUp();
			return false;
		}

		pageTable[i].swapPage = freeSwapPage; // The location of this page in the swap file
		pageTable[i].physicalPage = -1; // Only in the swap file, not in memory yet
		pageTable[i].valid = false; // Only in the swap file, not in memory yet
		pageTable[i].use = false;
		pageTable[i].dirty = false;
		pageTable[i].readOnly = false;  // if the code segment was entirely on 
						// a separate page, we could set its 
						// pages to be read-only

		DEBUG('a', "Virtual page %d allocated swap page %d\n", pageTable[i].virtualPage, pageTable[i].swapPage);
    }
	return true;
}


bool AddrSpace::translate(int vaddr, int *paddr)
{
	// Calculate the physical location
	unsigned int pageNumber = vaddr / PageSize;
	int remainder = vaddr % PageSize;

	// Verify the page is a valid one
	if(pageNumber > numPages)
	{
		return false;
	}

	// Set the physical location
	

	*paddr = (pageTable[pageNumber].physicalPage * PageSize + remainder);

	return pageTable[pageNumber].valid;
}


bool AddrSpace::readFile(OpenFile *executable)
{
	bool success;

	// Zero out the address space, to zero the unitialized data segment and the stack segment
	for(unsigned int i=0; i<numPages; i++)
	{
		// Get the physical address of the page
		int vPageStart, pPageStart;
		vPageStart = i*PageSize;
		success = translateVM(vPageStart, &pPageStart);
		if(!success)
		{
			return false;
		}

		// Zero out the page
		bzero( &(machine->mainMemory[pPageStart]), PageSize);
	}


	
    DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", noffH.code.virtualAddr, noffH.code.size);
	success = userReadWrite(noffH.code.virtualAddr, noffH.code.size, executable, noffH.code.inFileAddr, READ);
	if(!success)
		return false;
		
    DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", noffH.initData.virtualAddr, noffH.initData.size);
	if(noffH.initData.size != 0)	
	{
		success = userReadWrite(noffH.initData.virtualAddr, noffH.initData.size, executable, noffH.initData.inFileAddr, READ);
		if(!success)
			return false;		
	}

	return true;
}

// Return the first OpenUserFile object which the given filename
OpenUserFile* AddrSpace::findOpenUserFileByName(char *fileName)
{
	for(int i=0; i<openUserFiles.size(); i++)
	{
		int result;
		ASSERT(openUserFiles[i] != NULL);
		char *openFileName = openUserFiles[i]->getFileName();
		result = strcmp(openFileName, fileName);
		if(result == 0)
		{ 	// Match
			return openUserFiles[i];
		}
	}
	return NULL;
}

int	AddrSpace::addOpenUserFile(OpenUserFile *file)
{
	int freeIndex = -1;

	// Find a free index to add this at
	for(int i=0; i<openUserFiles.size(); i++)
	{
		if(openUserFiles[i] == NULL)
		{
			freeIndex = i;
			break;
		}
	}

	// Found a free location
	if(freeIndex != -1)
	{
		openUserFiles[freeIndex] = file;
		return freeIndex + UserFileCountOffset;
	}

	// Did not find a free location, add it onto the end
	openUserFiles.push_back(file);
	return ( openUserFiles.size() - 1) + UserFileCountOffset;
}

int AddrSpace::userReadWrite(int bufferLoc, int size, OpenFile *file, int fileOffset, int action)
{	
	int vStart, // The virtual address of where to start for a block
		vEnd,   // The virtual address of where to end for a block
		pStart, // The physical address of where to start for a block
		endOfPage, // The virtual address of the end of the page the data is on
		endOfData, // The virtual address of the end of all the data to R/W
		numBytesToCopy; // The number of bytes to copy for a block

	// Check if we are reading off of the end of the file
	if(action == READ && ( (fileOffset + size) >= file->Length() ))
		size = file->Length() - fileOffset;

	endOfData = bufferLoc + size;	

	// Amount copied so far
	int totalBytesCopied = 0;

	// Reads or writes the data, one block at a time
	while(totalBytesCopied < size)
	{
		// Start from here for this block
		vStart = bufferLoc + totalBytesCopied;

		// Find which comes first, the end of the page or the end of the data
		endOfPage = (vStart / PageSize + 1)*PageSize;
 
		// Stop at whichever comes first
		if(endOfPage < endOfData)
			vEnd = endOfPage;
		else
			vEnd = endOfData;

		// TODO vm
		// Based on the end address, determine how much to copy
		numBytesToCopy = vEnd - vStart;
		
		// Translate the virtual start address to a physical one
		bool result = translateVM(vStart, &pStart);
		if(!result)
			return -1; // Check for failure in translation (bad addresses)
		
		if(action == READ)
		{
			file->ReadAt( &(machine->mainMemory[pStart]), numBytesToCopy, fileOffset );
			pageTable[vStart/PageSize].dirty = true;
		}
		else if(action == WRITE)			
		{	
			file->WriteAt( &(machine->mainMemory[pStart]), numBytesToCopy, fileOffset );
		}
		else
			return -1;

		// Update the amount copied so far
		totalBytesCopied += numBytesToCopy;
		fileOffset += numBytesToCopy;
	}
    
	return totalBytesCopied;
}

bool AddrSpace::write(int bufferLoc, int size, int openFileID)
{
	// Console output
	if(openFileID == ConsoleOutput)
	{
		for(int i=0; i<size; i++)
		{
			// Get the physical address of the next char to write
			int pLocation;
			bool success = translateVM(bufferLoc+i, &pLocation);
			if(!success)
				return false;
			putchar( machine->mainMemory[pLocation] );
		}				
	}
	// Not Console output	
	else
	{
		openFileID -= UserFileCountOffset;
		// Ensure the openFileID is valid
		if(openFileID < 0 || openFileID >= openUserFiles.size() )
			return false;
		if(openUserFiles[openFileID] == NULL)
			return false;

		// openFileID appears valid, start writing
		int sysFileIndex = openUserFiles[openFileID]->getIndex();
		OpenFile *file = sysOpenFileList->at(sysFileIndex)->getFile();
		int offset = openUserFiles[openFileID]->getOffset();
		int numWritten = userReadWrite(bufferLoc, size, file, offset, WRITE);
		openUserFiles[openFileID]->setOffset(offset+numWritten);
	}

	return true;
}


int AddrSpace::read(int bufferLoc, int size, int openFileID)
{
	// Console input
	if(openFileID == ConsoleInput)
	{		
		int numRead = 0;

		// Read all that we can
		for(numRead=0; numRead<size; numRead++)
		{
			// Attempt to read the next character from the console and store it in the buffer
			char readChar = getchar();

			// Get the physical address of the next spot to read into
			int pLocation;
			bool success = translateVM(bufferLoc+numRead, &pLocation);
			if(!success)
				return -1; // Error translating buffer address

			// Store it in the buffer
			machine->mainMemory[pLocation] = readChar;
		}

		return numRead;
	}
	// Not Console input
	else
	{
		openFileID -= UserFileCountOffset;
		// Ensure the openFileID is valid
		if(openFileID < 0 || openFileID >= openUserFiles.size() )
			return false;
		if(openUserFiles[openFileID] == NULL)
			return false;

		// openFileID appears valid, start reading
		int sysFileIndex = openUserFiles[openFileID]->getIndex();
		OpenFile *file = sysOpenFileList->at(sysFileIndex)->getFile();
		int offset = openUserFiles[openFileID]->getOffset();
		int numRead = userReadWrite(bufferLoc, size, file, offset, READ);
		openUserFiles[openFileID]->setOffset(offset+numRead);
		return numRead;
	}	
}

void AddrSpace::closeUserFile(int openFileID)
{
	openFileID -= UserFileCountOffset;
	// Ensure the openFileID is valid	
	if(openFileID < 0 || openFileID >= openUserFiles.size() )
		return;
	if(openUserFiles[openFileID] == NULL)
		return;

	// Delete the open user file
	OpenUserFile *openFile = openUserFiles[openFileID];
	openUserFiles[openFileID] = NULL;
	delete openFile;
}

void AddrSpace::loadPage(int vaddr, int physicalPage)
{
	// Get the page number from the virtual address
	int pageNumber = vaddr / PageSize;

	// Copy page from the swapfile into memory
	MemoryManager *memoryManager = getMemoryManager();
	memoryManager->loadPage( physicalPage, pageTable[pageNumber].swapPage );
	// Update the bits
	pageTable[pageNumber].physicalPage = physicalPage;
	pageTable[pageNumber].valid = TRUE;
	pageTable[pageNumber].dirty = FALSE;
	pageTable[pageNumber].lastUsed = stats->totalTicks;


	printf("L [%d]: [%d] -> [%d] \n", pid, pageNumber, physicalPage);
}


void AddrSpace::writePage(int virtualPage)
{
	// Check if dirty and it needs to be written
	if(pageTable[virtualPage].valid == false)
		printf("VERY BAD: AddrSpace 0x%x told to write out virtual page %d that is not in memory \n", this, virtualPage);


	if(pageTable[virtualPage].dirty)
	{		
		MemoryManager *memoryManager = getMemoryManager();
		memoryManager->writePage( pageTable[virtualPage].physicalPage, pageTable[virtualPage].swapPage );
		printf("S [%d]: [%d] \n", pid, pageTable[virtualPage].physicalPage);	
	}
	else
		printf("E [%d]: [%d] \n", pid, pageTable[virtualPage].physicalPage);	

	// Update the bits
	pageTable[virtualPage].valid = false;
	pageTable[virtualPage].dirty = false;



}

int AddrSpace::getLRUPage()
{
	int minValue = INT_MAX;
	int minIndex = -1;

	for(int i=0; i<numPages; i++)
	{
		if(pageTable[i].lastUsed < minValue && pageTable[i].valid)
		{
			minValue = pageTable[i].lastUsed;
			minIndex = i;
		}
	
	}
	
	return minIndex;
}

bool AddrSpace::writeExecToSwapFile(OpenFile *executable)
{
	bool success = true;
	char *buffer = new char[PageSize];
	int readFrom, writeTo, leftInPage, leftToWrite, virtualPage, swapPage, physicalPage;
	MemoryManager *memoryManager = getMemoryManager();

	// Create a zeroed out buffer
	for(int i=0; i<PageSize; i++)
		buffer[i] = 0;

	// Zero out the initial pages in the address space
	// Makes it so we don't have to deal with zeroeing out the BSS data later
	for(int i=0; i<numPages; i++)
	{
		swapPage = pageTable[i].swapPage;
		memoryManager->writeBufferToSwapPage(buffer, swapPage);
	}

	// Read in the code - one page at a time
	// Read in a page at a time
	readFrom = noffH.code.inFileAddr;
	writeTo = noffH.code.virtualAddr;
	leftToWrite = noffH.code.size;	

    DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", noffH.code.virtualAddr, noffH.code.size);
	while(leftToWrite > 0)
	{
		leftInPage = PageSize - (writeTo) % PageSize;
		// Read the rest of the page into the buffer
		executable->ReadAt(buffer+(PageSize-leftInPage), leftInPage, readFrom);
		// Get the virtual page number	
		virtualPage = writeTo/PageSize;
		// Get the corresponding swap page and write directly to it
		swapPage = pageTable[virtualPage].swapPage;
		memoryManager->writeBufferToSwapPage(buffer, swapPage);

		leftToWrite -= leftInPage;
		writeTo += leftInPage;
		readFrom += leftInPage;
	}
	
	readFrom = noffH.initData.inFileAddr;
	writeTo = noffH.initData.virtualAddr;
	leftToWrite = noffH.initData.size;

    DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", noffH.initData.virtualAddr, noffH.initData.size);
	while(leftToWrite > 0)
	{
		leftInPage = PageSize - (writeTo) % PageSize;
		// Read the rest of the page into the buffer
		executable->ReadAt(buffer+(PageSize-leftInPage), leftInPage, readFrom);
	
		virtualPage = writeTo/PageSize;
		swapPage = pageTable[virtualPage].swapPage;
		memoryManager->writeBufferToSwapPage(buffer, swapPage);

		leftToWrite -= leftInPage;
		writeTo += leftInPage;
		readFrom += leftInPage;
	}

	delete [] buffer;
	return success;
}

bool AddrSpace::translateVM(int vaddr, int *paddr)
{
	int vPage = vaddr / PageSize;
	int vOffset = vaddr % PageSize;

	if(vPage > numPages)
		return false;

	if(pageTable[vPage].valid)
	{
		(*paddr) = pageTable[vPage].physicalPage*PageSize+vOffset;
		return true;
	}
	
	// Bring the page into memory
	ExceptionType exception = PageFaultException;
	machine->RaiseException(exception, vaddr);
	if(pageTable[vPage].valid)
	{
		(*paddr) = pageTable[vPage].physicalPage*PageSize+vOffset;
		return true;
	}
	return false;
}


























