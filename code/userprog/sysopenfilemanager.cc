#include "sysopenfilemanager.h"
#include <string.h> // strcmp
//-----------------------------------------------------------------------------
// SysOpenFileManager::SysOpenFileManager
//
//     Constructor
//-----------------------------------------------------------------------------

SysOpenFileManager::SysOpenFileManager() : sysOpenFilesMap(MAX_SYS_OPEN_FILES) {}

//-----------------------------------------------------------------------------
// SysOpenFileManager::~SysOpenFileManager
//
//     Destructor
//-----------------------------------------------------------------------------

SysOpenFileManager::~SysOpenFileManager() {}

//-----------------------------------------------------------------------------
// SysOpenFileManager::addFile
//
//     Adds a file to the list of currently open system files.
//-----------------------------------------------------------------------------

int SysOpenFileManager::addFile(SysOpenFile file) {

    int fileIndex = sysOpenFilesMap.Find();
    if (fileIndex == -1) {
        printf("No more room for any more open system files.\n");
        return -1;
    } else {
        sysOpenFileList[fileIndex] = file;
        return fileIndex;
    }
}

//-----------------------------------------------------------------------------
// SysOpenFileManager::getFile
//
//     Returns the system open file of that filename and its index.
//-----------------------------------------------------------------------------

SysOpenFile* SysOpenFileManager::getFile(char* filename, int& index) {

    for (int i = 2; i < MAX_SYS_OPEN_FILES; i++) {
        
        if (sysOpenFilesMap.Test(i)) {
            if (!strcmp(filename, sysOpenFileList[i].filename)) {
                index = i;
                return &sysOpenFileList[index];
            }
        }
    }
    return NULL; // couldn't find a file by that name
}

//-----------------------------------------------------------------------------
// SysOpenFileManager::getFile
//
//     Same as above, but use the index into array if we know that information.
//-----------------------------------------------------------------------------

SysOpenFile* SysOpenFileManager::getFile(int index) {

    if (sysOpenFilesMap.Test(index)) {
        return sysOpenFileList + index;
    } else {
        return NULL;
    }
}
