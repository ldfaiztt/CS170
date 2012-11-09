/*
 * MemoryManager implementation
 *
 * Used to facilitate contiguous virtual memory.  Utilizes the provided bitmap
 * data structure to store the state of pages in the page table.
*/

#include "MemoryManager.h"
#include "machine.h"

// Constructor
MemoryManager::MemoryManager() {
    physPageAllocation = new BitMap(NumPhysPages);
}

// Destructor
MemoryManager::~MemoryManager() {
    delete physPageAllocation;
}

// Allocates the first clear page
int MemoryManager::getPage() {

    int pageIndex = physPageAllocation->Find(); // sets the bit as a side-effect
    if (pageIndex == -1) {
        DEBUG('m', "Unable to find a page from the page table.");
        ASSERT(FALSE);
    } else {
        return pageIndex;
    }
}

// Frees a page from the table
void MemoryManager::clearPage(int pageIndex) {
    physPageAllocation->Clear(pageIndex);
}

// Returns the number of available pages
int MemoryManager::getNumFreePages() {
    return physPageAllocation->NumClear();
}
