#include "fscalls.h"



// Implementation of various file i/o system calls.
void scReturnInt(int i) {
  machine->WriteRegister(2, i);
}


char* scGetStringArg(int index, bool copy) {
  int vAddress = machine->ReadRegister(4 + index);
  int pAddress = 0;
  currentThread->space->Translate(vAddress, &pAddress, true);

  char* uString = machine->mainMemory + pAddress;

  if (copy) {
    char* kString = new char[strlen(uString) + 1];
    strcpy(kString, uString);
    return kString;
  } else {
    return uString;
  }
}


int scGetUspacePtrArg(int index) {
  return machine->ReadRegister(4 + index);
}


int scGetIntArg(int index) {
  int i = machine->ReadRegister(4 + index);
  return i;
}


int scCreate(char* fileName) {
  bool success = fileSystem->Create(fileName, 0);

  if (!success) {
    DEBUG('1', "Failed to create file");
    return -1;
  }

  return 0;
}


int scOpen(char* fileName) {
  SysOpenFile *sysFile;
  bool fileOpen = false;

  // Attempt to look up the file (by name) in the system file table.
  for (int i = 0; i < sysOpenFileCount; i++) {
    sysFile = sysOpenFiles[i];
    if (strcmp(sysFile->fileName, fileName) == 0) {
      fileOpen = true;
      break;
    }
  }

  if (!fileOpen) {
    // File is not yet open: Open the file.
    OpenFile *file = fileSystem->Open(fileName);
    if (file == 0) {
      DEBUG('f', "Open(): File not found\n");
      return -1;
    }
    sysFile = new SysOpenFile();
    sysFile->file = file;
    sysFile->fileID = lastSysFileId++;
    sysFile->fileName = fileName;
    sysOpenFiles[sysOpenFileCount++] = sysFile;
  } else {
    // File is already open.
  }
  
  sysFile->openCount += 1;

  // Make a new UserOpenFile instance.
  UserOpenFile *userFile = new UserOpenFile();
  userFile->fileName = fileName;
  userFile->sysOpenFilePtr = sysFile;
  currentThread->space->pcb->openUserFiles[currentThread->space->pcb->userOpenFileCount++] = userFile;

  return sysFile->fileID;
}


void memcpyFromUser(char *kernel, int user, int len) {
  int paddr;

  for (int i = 0; i < len; i++) {
    if (!currentThread->space->Translate((user + i), &paddr, 0)) {
      return;
    }
    kernel[i] = machine->mainMemory[paddr];
  }

  return;
}


void memcpyToUser(int user, char* kernel, int len) {
  int paddr;

  for (int i = 0; i < len; i++) {
    if (!currentThread->space->Translate((user + i), &paddr, TRUE)) {
      return;
    }
    machine->mainMemory[paddr] = kernel[i];
  }

}


void userRead(int uspace_dest, char* src_buffer, int size) {
  // Read from src_buffer into diskBuffer. Once diskBuffer is full, copy it into uspace_dest.
  // Repeat until size bytes have been written to uspace_dest, one diskBuffer at a time.
  int diskBufferSize = PageSize;
  for (int i = 0; i < size / diskBufferSize; i++) {
    memcpy(diskBuffer, src_buffer + i * diskBufferSize, diskBufferSize);
    memcpyToUser(uspace_dest + i * diskBufferSize, diskBuffer, diskBufferSize); 
  }
  memcpy(diskBuffer, src_buffer + diskBufferSize * (size / diskBufferSize), size % diskBufferSize);
  memcpyToUser(uspace_dest + diskBufferSize * (size / diskBufferSize), diskBuffer, size % diskBufferSize);
}


int scRead(int uspace_buffer, int size, OpenFileId id) {
  char buffer[size + 1];
  if (id == ConsoleOutput) {
    // Nothing happens.
    return 0;
  } else if (id == ConsoleInput) {
    for (int i = 0; i < size; i++) {
      buffer[i] = getchar();
    }
    userRead(uspace_buffer, buffer, size);
    return size;
  } else {
    for (int i = 0; i < currentThread->space->pcb->userOpenFileCount; i++) {
      UserOpenFile *current = currentThread->space->pcb->openUserFiles[i];
      if (current->sysOpenFilePtr->fileID == id) {
	// File is open
	OpenFile *file = current->sysOpenFilePtr->file;
	int read = file->ReadAt(buffer, size, current->seekPosition);
	userRead(uspace_buffer, buffer, size);
	current->seekPosition += read;
	return read;
      }
    }
    DEBUG('f', "FILE NOT OPEN");
    return 0;
  }


  userRead(uspace_buffer, buffer, size);

  return 0;
}


void userWrite(char* dest_buffer, int uspace_src, int size) {
  // Read from uspace_src into diskBuffer. Once diskBuffer is full, copy it to dest_buffer.
  // Repeat until size bytes have been read from uspace_src, one diskBuffer at a time.
  int diskBufferSize = PageSize;
  for (int i = 0; i < size / diskBufferSize; i++) {
    memcpyFromUser(diskBuffer, uspace_src + i * diskBufferSize, diskBufferSize);
    memcpy(dest_buffer + i * diskBufferSize, diskBuffer, diskBufferSize); 
  }
  memcpyFromUser(diskBuffer, uspace_src + diskBufferSize * (size / diskBufferSize), size % diskBufferSize);
  memcpy(dest_buffer + diskBufferSize * (size / diskBufferSize), diskBuffer, size % diskBufferSize);
}


int scWrite(int uspace_buffer, int size, OpenFileId id) {
  char buffer[size + 1];

  if (id == ConsoleOutput) {
    userWrite(buffer, uspace_buffer, size);
    buffer[size] = 0; // To make printf happy.
    printf("%s", buffer);
    return size;
  } else if (id == ConsoleInput) {
    // Nothing happens.
    return 0;
  } else {
    for (int i = 0; i < currentThread->space->pcb->userOpenFileCount; i++) {
      UserOpenFile *current = currentThread->space->pcb->openUserFiles[i];
      if (current->sysOpenFilePtr->fileID == id) {
	// File is open
	OpenFile *file = current->sysOpenFilePtr->file;
        file->fileID = id;
	userWrite(buffer, uspace_buffer, size);
	int bytesWritten = file->WriteAt(buffer, size, current->seekPosition);
	current->seekPosition += bytesWritten;
	return bytesWritten;
      }
    }
    DEBUG('f', "FILE NOT OPEN");
    return -1;
  }
}


void scClose(OpenFileId id) {
  for (int i = 0; i < currentThread->space->pcb->userOpenFileCount; i++) {
    UserOpenFile *current = currentThread->space->pcb->openUserFiles[i];
    if (current->sysOpenFilePtr->fileID == id) {
      currentThread->space->pcb->userOpenFileCount -= 1;
      currentThread->space->pcb->openUserFiles[i] = currentThread->space->pcb->
	openUserFiles[currentThread->space->pcb->userOpenFileCount];
      currentThread->space->pcb->openUserFiles[currentThread->space->pcb->userOpenFileCount] = 0;
      DEBUG('1', "Closed UserOpenFile\n");
     
      // Check if system file entzry should be deleted.
      SysOpenFile *sysFile = current->sysOpenFilePtr;
      sysFile->openCount -= 1;
      DEBUG('1', "SysOpenFile users=%d\n", sysFile->openCount);

      if (sysFile->openCount == 0) {
	DEBUG('1', "Closed SysOpenFile\n");
	sysOpenFileCount -= 1;
	sysOpenFiles[i] = sysOpenFiles[sysOpenFileCount];
	sysOpenFiles[sysOpenFileCount] = 0;
      
	delete sysFile;
      }

      return;
    }
  }
  
  DEBUG('f', "File is not open\n");
   

}
