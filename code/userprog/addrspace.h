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

#include <vector>
#include "copyright.h"
#include "filesys.h"
#include "memorymanager.h"
#include "machine.h"
#include "noff.h"
#include "openuserfile.h"
#include "nachossyscalls.h"

#define UserFileCountOffset 2
#define UserStackSize		1024 	// increase this as necessary!

enum {READ = 0, WRITE = 1};


class AddrSpace {
  public:
	AddrSpace(int pid) {this->pid = pid;}		// Create an empty AddrSpace object
    AddrSpace(OpenFile *executable, int pid);	// Create an address space,
					// initializing it with the program
					// stored in the file "executable"
    ~AddrSpace();			// De-allocate an address space

	int			addOpenUserFile(OpenUserFile *file); // Add an openUserFile, return the ID of it
	void 		closeUserFile(int openFileID);
	AddrSpace* 	duplicate(int pid);			// Duplicate the address space, except for allocating new pages
	OpenUserFile* findOpenUserFileByName(char *fileName); // Self explanatory
	int					getLRUPage(); // Returns index of LRU page for this page table
	MemoryManager* 		getMemoryManager();	
	TranslationEntry* 	getPage(int index) {return &(pageTable[index]); } // TODO CHECK BOUNDS
	int 		getPagesRequired(); 	// Get the number of pages required by this address space
    void 		InitRegisters();		// Initialize user-level CPU registers,
	bool 		isCreated(); 			// Get the status of a created address space										// before jumping to user code
	void		loadPage(int vaddr, int frame);
	int			read(int bufferLoc, int size, int openFileID);	// Read from a file / console
	bool		readFile(OpenFile*); // Read in from a file to load the executable
   	int 		ReadFile(int virtAddr, OpenFile* file, int size, int fileAddr);
    void 		RestoreState();			// info on a context switch 
    void 		SaveState();			// Save/restore address space-specific
	bool		translate(int, int*);  // Translate a virtual address
	bool		translateVM(int, int*);
	int 		userReadWrite(int bufferLoc, int size, OpenFile *file, int offset, int action); // Helper func to read/write
	bool		write(int bufferLoc, int size, int openFileID);  // Write to a file / console
	void		writePage(int pageIndex);
	bool		writeExecToSwapFile(OpenFile *executable);



  private:
    TranslationEntry*	pageTable;	// Assume linear page table translation
	unsigned int 		numPages;		// Number of pages in the virtual address space
	bool				createdSuccessfully; // Whether the address space allocated enough space
	int					registers[NumTotalRegs]; // Stored machine registers
	std::vector<OpenUserFile*> openUserFiles;
	NoffHeader 			noffH;
	int					pid;


	void				cleanUp();
	bool				allocatePages();
};

#endif // ADDRSPACE_H
