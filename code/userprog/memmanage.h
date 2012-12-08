#pragma once

#include "bitmap.h"
//#include "synch.h"

class MemoryManager {
    int pages;
    BitMap *pagemap;
    //Lock *memlock;

public:
    MemoryManager(int pages);
    ~MemoryManager();

    int getFreePages();
    int getPage();
    void clearPage(int page);
};
