/*
 * PCB header
 *
 * A process control block stores all the necessary information about a process.
*/

#ifndef PCB_H
#define PCB_H

#include "bitmap.h"
#include "useropenfile.h"

// Process status
#define P_GOOD    0;
#define P_BAD     1;
#define P_RUNNING 2;
#define P_BLOCKED 3;

#define MAX_NUM_FILES_OPEN 32

class Thread;

class PCB {

    public:
        PCB(int pid, int parentPID);
        ~PCB();
        int getPID();
        int status;
        Thread* process;
        int addFile(UserOpenFile file);
        UserOpenFile* getFile(int fileID);
        void removeFile(int fileID);

    private:
        BitMap openFilesBitMap;
        int pid;
        int parentPID;
        UserOpenFile userOpenFileList[MAX_NUM_FILES_OPEN];
};

#endif // PCB_H
