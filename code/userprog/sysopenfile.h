#ifndef SYSOPENFILE_H
#define SYSOPENFILE_H

#include "filesys.h"

class SysOpenFile {
    
    public:
        OpenFile* file;
        int fileID;
        char* filename;
        int numProcessesAccessing;

        void closedBySingleProcess();
};

#endif // SYSOPENFILE_H
