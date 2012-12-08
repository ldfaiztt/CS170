#ifndef VMM_H
#define VMM_H
#include "bitmap.h"
#include "translate.h"
#include <deque>

class VMemoryManager {
    int ppages; // Number of physical pages
    int vpages; //Number of virtual pages
    BitMap *pagemap;
    BitMap *sectormap;
    //Lock *memlock;
    SwapOpenFile *swapFile;
    std::deque<TranslationEntry*> *memQueue;

public:
    VMemoryManager(int nppages, int nvpages);
    ~VMemoryManager();

    int getFreePages();
    int getPage();
    int getSector();
    int storePage(TranslationEntry* entry);
    int loadPage(TranslationEntry* entry);
    int clonePage(TranslationEntry* dest, TranslationEntry* src);
    void clearPage(TranslationEntry *entry);
};

#endif
