#include "psblock.h"
#include "thread.h"
#include "synch.h"


PCB::PCB(SpaceID pid, SpaceID parent, Thread *thread) : pid(pid), parent(parent), thread(thread) {
    status = 0;
    done = 0;
    lock = new Lock("PCB lock");
    condition = new Condition("PCB condition");

    userOpenFileCount = 0;
    openUserFiles = new UserOpenFile*[MAX_USER_FILES];
}

PCB::~PCB() {
    delete lock;
    delete condition;
    delete[] openUserFiles;
}

SpaceID PCB::GetPID() {
    return pid;
}

SpaceID PCB::GetParentPID() {
    return parent;
}

void PCB::Exit(int status) {
    this->status = status;

    lock->Acquire();
    done = 1;
    condition->Broadcast(lock);
    lock->Release();
}

int PCB::Join() {
    lock->Acquire();
    if (done == 0) {
        condition->Wait(lock);
    }
    lock->Release();

    return status;
}
