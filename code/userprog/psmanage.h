#pragma once

#include "bitmap.h"
#include "psblock.h"
#include "synch.h"

class ProcessManager {
    int processes;
    BitMap *pidmap;
    PCB **processblocks;

public:
    ProcessManager(int processes);
    ~ProcessManager();

    PCB *GetNewPCB(PCB *parent, Thread *thread);
    PCB *GetPCB(SpaceID pid);

    int WaitPCB(SpaceID pid);
};
