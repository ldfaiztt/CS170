#pragma once

#include "openfile.h"
#include "fscalls.h"

#define MAX_USER_FILES 32


typedef int SpaceID;

class Thread;
class Lock;
class Condition;

class PCB {
    friend class ProcessManager;

    PCB(SpaceID pid, SpaceID parent, Thread *thread);
    ~PCB();

    SpaceID pid;
    SpaceID parent;

    Thread *thread;

    Lock *lock;
    Condition *condition;
    int status;
    int done;

public:
    Lock *waitlock;
    int waiting;

    SpaceID GetPID();
    SpaceID GetParentPID();

    void Exit(int status);
    int Join();

    UserOpenFile **openUserFiles;
    int userOpenFileCount;
};

