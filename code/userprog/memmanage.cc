#include "memmanage.h"

MemoryManager::MemoryManager(int pages) : pages(pages) {
    //memlock = new Lock("memory manager");
    pagemap = new BitMap(pages);
}

MemoryManager::~MemoryManager() {
    //delete memlock;
    delete pagemap;
}

int MemoryManager::getFreePages() {
    int ret = pagemap->NumClear();

    return ret;
}

int MemoryManager::getPage() {
    //memlock->Lock();
    int ret = pagemap->Find();
    //memlock->Unlock();

    return ret;
}

void MemoryManager::clearPage(int page) {
    ASSERT(page >= 0 && page < pages);

    //memlock->Lock();
    pagemap->Clear(page);
    //memlock->Unlock();
}
