#include "psmanage.h"

ProcessManager::ProcessManager(int processes) : processes(processes) {
    ASSERT(processes > 0);
    pidmap = new BitMap(processes);
    processblocks = new PCB*[processes];
}

ProcessManager::~ProcessManager() {
    delete pidmap;
    delete[] processblocks;
}

PCB *ProcessManager::GetNewPCB(PCB *parent, Thread *thread) {
    SpaceID newpid = pidmap->Find();
    if (newpid == -1) {
        return NULL;
    }

    PCB *ret;
    if (parent) {
        ret = new PCB(newpid, parent->pid, thread);
    } else {
        ret = new PCB(newpid, -1, thread);
    }

    processblocks[newpid] = ret;

    return ret;
}

PCB *ProcessManager::GetPCB(SpaceID pid) {
    if (pid < 0 || pid >= processes) {
        return NULL;
    }
    if (!pidmap->Test(pid)) {
        return NULL;
    }

    return processblocks[pid];
}

int ProcessManager::WaitPCB(SpaceID pid) {
    PCB *pcb = GetPCB(pid);
    if (pcb == NULL) {
        return -1;
    }

    int ret = pcb->Join();

    return ret;
}
