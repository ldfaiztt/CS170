//----------------------------------------------------------------------
// SysOpenFileManager
//     
//     Class to manage a list of all the currently open system files,
//     used for all the system calls in Project 2, Part 2.
//----------------------------------------------------------------------

#ifndef SYSOPENFILEMANAGER_H
#define SYSOPENFILEMANAGER_H

#define MAX_SYS_OPEN_FILES 32

#include "sysopenfile.h"
#include "bitmap.h"

class SysOpenFileManager {

    public:
        SysOpenFileManager();
        ~SysOpenFileManager();
        int addFile(SysOpenFile file);
        SysOpenFile* getFile(char* filename, int& index);
        SysOpenFile* getFile(int index);

    private:
        SysOpenFile sysOpenFileList[MAX_SYS_OPEN_FILES];
        BitMap sysOpenFilesMap; // managing how many files open
};

#endif // SYSOPENFILEMANAGER_H
