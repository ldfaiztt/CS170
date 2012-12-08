#include "vmemmanage.h"
#include "machine.h"
#include "filesys.h"
#include "thread.h"

extern FileSystem* fileSystem;
extern Machine* machine;
extern Thread* currentThread;

char empty[NumVmPages * PageSize];

VMemoryManager::VMemoryManager(int nppages, int nvpages) {
	pagemap = new BitMap(nppages);
	sectormap = new BitMap(nvpages);
	ppages = nppages;
	vpages = nvpages;
	Close(OpenForWrite("SWAP"));
	swapFile = new SwapOpenFile(OpenForReadWrite("SWAP", FALSE));
	memset(empty, '0', NumVmPages * PageSize);
	swapFile->WriteAt(empty, NumVmPages * PageSize, 0);
	memQueue = new std::deque<TranslationEntry*>();
}

VMemoryManager::~VMemoryManager() {
	delete pagemap;
}

int VMemoryManager::getFreePages() {
	int ret = sectormap->NumClear();

	return ret;
}

int VMemoryManager::getPage() {
	// In the VM version, physical pages aren't allocated just yet.
	return -1;
}

int VMemoryManager::getSector() {
	return sectormap->Find();
}

int VMemoryManager::storePage(TranslationEntry* entry) {
	//ASSERT(entry->inMem);
	//printf("Store vpage %d at %x (%d bytes)\n", entry->virtualPage, entry->swapSector * PageSize, PageSize);

	if (entry->dirty) {
		entry->dirty = FALSE;
		swapFile->WriteAt(
				machine->mainMemory + (entry->physicalPage * PageSize),
				PageSize, entry->swapSector * PageSize);
		DEBUG(
				'2',
				"S %d: %d\n",
				currentThread->space && currentThread->space->pcb ?
						currentThread->space->pcb->GetPID() : -1,
				entry->virtualPage);
	} else {
		DEBUG(
				'2',
				"E %d: %d\n",
				currentThread->space && currentThread->space->pcb ?
						currentThread->space->pcb->GetPID() : -1,
				entry->virtualPage);
	}
	return 0;
}

//----------------------------------
//Load a page to handle a page fault 
//----------------------------------

int VMemoryManager::loadPage(TranslationEntry* entry) {
	//printf("Request load of vpage %d inmem=%d\n", entry->virtualPage, entry->inMem);
	ASSERT(!entry->inMem);
	//it is not in memory now
	// Figure out which physical page should receive the swap page.

	int destPage;

	// If there is a physical available, use that page
	// otherwise no free physical page, must swap an old one to disk first.
	if (pagemap->NumClear() > 0) {
		destPage = pagemap->Find();
		memQueue->push_back(entry);
	} else {

		TranslationEntry *oldest;
		// Pick a page to remove from memQueue
		// Second chance FIFO
		int numDuplicates = 0;
		for (int i = 0; i < (int) memQueue->size() * 2; i++) {
			if (memQueue->at(i)->use) {
				memQueue->at(i)->use = false;
				memQueue->push_back(memQueue->at(i));
				numDuplicates++;
			} else {
				oldest = memQueue->at(i);
				numDuplicates++;
				break;
			}
		}

		// destPage stores the physical page to be used
		destPage = oldest->physicalPage;

		// Remove from TLB
		for (int i = 0; i < TLBSize; i++) {
			if (machine->tlb[i].virtualPage == oldest->virtualPage
					&& machine->tlb[i].valid) {
				// We've found a TLB entry for the page we're about to remove.
				// Invalidate its TLB entry and copy any changes back to addrspace.
				machine->tlb[i].valid = FALSE;
				TranslationEntry *pageTable = currentThread->space->pageTable;
				TranslationEntry *addrspaceEntry = NULL;
				for (int j = 0; j < currentThread->space->numPages; j++) {
					if (pageTable[j].valid
							&& pageTable[j].virtualPage
									== machine->tlb[i].virtualPage) {
						addrspaceEntry = &(pageTable[j]);
						break;
					}
				}ASSERT(addrspaceEntry != NULL);
				ASSERT(machine->tlb[i].use);
				addrspaceEntry->dirty = machine->tlb[i].dirty;
				addrspaceEntry->use = machine->tlb[i].use;
				break;
			}
		}

		// swap out the old page to the disk, and mark this logical page is not available anymore
		oldest->use = false;
		oldest->inMem = false;
		storePage(oldest);

		// Delete second chance FIFO duplicates
		for (int i = 0; i < numDuplicates; i++) {
			memQueue->pop_front();
		}

		// Update the input parameter entry and add it to the queue.
		memQueue->push_back(entry);
	}

	entry->physicalPage = destPage;

	// Then load the corresponding page from the disk (SWAP file)  into memory.
	if (!entry->firstUse) {
		swapFile->ReadAt(machine->mainMemory + (entry->physicalPage * PageSize),
				PageSize, entry->swapSector * PageSize);
	}
	entry->inMem = true;

	// Read data from the SwapOpenFile disk file object pointed
	// by swapFile field using its ReadAt method to copy the desired page, specified by "entry", to mainMemory.
	// "entry" has the swap sector number in the disk, the physical number destPage in mainMemory.
	// swapFile is defined in .h

	//printf("Read %d bytes into physical page %d\n", read, destPage);
	if (entry->firstUse) {
		DEBUG(
				'2',
				"Z %d: %d -> %d\n",
				currentThread->space && currentThread->space->pcb ?
						currentThread->space->pcb->GetPID() : -1,
				entry->virtualPage, entry->physicalPage);
		entry->firstUse = FALSE;
	} else {
		DEBUG(
				'2',
				"L %d: %d -> %d\n",
				currentThread->space && currentThread->space->pcb ?
						currentThread->space->pcb->GetPID() : -1,
				entry->virtualPage, entry->physicalPage);
	}
	return 0;
}

void VMemoryManager::clearPage(TranslationEntry *entry) {
	//    ASSERT(page >= 0 && page < vpages);
	//TODO(ian)
	//memlock->Lock();
	//pagemap->Clear(page);

	//memlock->Unlock();
	//printf("start clear\n");
	if (entry->inMem) {
		bool erased = FALSE;
		for (int i = 0; i < memQueue->size(); i++) {
			TranslationEntry *current = memQueue->at(i);
			if (current == entry) {
				memQueue->erase(memQueue->begin() + i);
				erased = TRUE;
				break;
			}
		}ASSERT(erased);
		pagemap->Clear(entry->physicalPage);
	}

	sectormap->Clear(entry->swapSector);
	// Erasing the swap file isn't technically necessary, but helps track down errors.
	swapFile->WriteAt(empty, PageSize, entry->swapSector * PageSize);

	//  printf("end clear\n");
}

int VMemoryManager::clonePage(TranslationEntry* dest, TranslationEntry* src) {
	char buffer[PageSize];
	//DEBUG('1',"D %d\n", src->virtualPage);

	if (src->inMem) {
		swapFile->WriteAt(machine->mainMemory + (src->physicalPage * PageSize),
				PageSize, src->swapSector * PageSize);

	}
	swapFile->ReadAt(buffer, PageSize, src->swapSector * PageSize);
	swapFile->WriteAt(buffer, PageSize, dest->swapSector * PageSize);
	return 1;
}
