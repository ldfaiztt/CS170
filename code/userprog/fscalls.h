#ifndef FSCALLS_H
#define FSCALLS_H



#define MAX_SYS_FILES 128


#define ConsoleInput	0  
#define ConsoleOutput	1  

typedef int OpenFileId;

struct SysOpenFile {
  SysOpenFile() {openCount = 0;}
  // Nachos FS file.
  OpenFile *file;
  int fileID;
  char *fileName;

  // Number of users who have opened it.
  int openCount;
};


struct UserOpenFile {
  UserOpenFile() {seekPosition = 0;}

  char *fileName;
  SysOpenFile *sysOpenFilePtr;
  int seekPosition;
};

// Some convenient utility functions for bridging the userland/kernel gap.
void scReturnInt(int i);

char* scGetStringArg(int index);

int scGetIntArg(int index);


int scCreate(char* fileName);

int scOpen(char* fileName);

int scRead(char* fileName, int size, OpenFileId id);

int scWrite(char* fileName, int size, OpenFileId id);

void scClose(OpenFileId id);

#endif
