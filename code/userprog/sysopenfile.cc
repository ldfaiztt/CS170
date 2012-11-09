#include "sysopenfile.h"

//-----------------------------------------------------------------------------
// SysOpenFile::closedBySingleProcess
//
//     Notifies the system open file that a process doesn't need it anymore,
//     and if it was the last one, we'll close the file itself, too.
//-----------------------------------------------------------------------------

void SysOpenFile::closedBySingleProcess() {

    if (numProcessesAccessing <= 0) {
        return; // something is wrong...
    }
    numProcessesAccessing--;
    if (numProcessesAccessing == 0) {
        delete filename;
        delete file;
    }
}
