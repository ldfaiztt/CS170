#ifndef PAGEMANAGER_H
#define PAGEMANAGER_H
#include "bitmap.h"


struct PageManager {
  int pages;
  BitMap *pagemap;
  
  PageManager(int pages);
  
  void storePage();
  void unstorePage();
};
#endif
