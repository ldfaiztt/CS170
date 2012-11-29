// filehdr.cc 
//	Routines for managing the disk file header (in UNIX, this
//	would be called the i-node).
//
//	The file header is used to locate where on disk the 
//	file's data is stored.  We implement this as a fixed size
//	table of pointers -- each entry in the table points to the 
//	disk sector containing that portion of the file data
//	(in other words, there are no indirect or doubly indirect 
//	blocks). The table size is chosen so that the file header
//	will be just big enough to fit in one disk sector, 
//
//      Unlike in a real system, we do not keep track of file permissions, 
//	ownership, last modification date, etc., in the file header. 
//
//	A file header can be initialized in two ways:
//	   for a new file, by modifying the in-memory data structure
//	     to point to the newly allocated data blocks
//	   for a file already on disk, by reading the file header from disk
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"

#include "system.h"
#include "filehdr.h"

//----------------------------------------------------------------------
// FileHeader i-node constructor
// That is a two-level mapping:  each entry of i-node is an indrector data block pointer
// The file header needs to contain a list of sectors which are the i-nodes and 
//          file logical-physical block mapping information loaded from those sectos.
//----------------------------------------------------------------------
FileHeader::FileHeader() {
    DEBUG('F', "FileHeader constructor called\n");
    for (int i = 0; i < NumDirect; i++) {
        indirectSectors[i] = -1;
        indirectBlocks[i] = NULL;
    }
}

FileHeader::~FileHeader() {
    for (int i = 0; i < NumDirect; i++) {
        if (indirectBlocks[i]) {
            delete[] indirectBlocks[i];
        }
    }
}

//----------------------------------------------------------------------
// Give a mapping from file logical block (sector) number to the physical sector number
//
//----------------------------------------------------------------------
int *FileHeader::sectorMap(int virtSect) {
    if (virtSect >= numSectors) {
        DEBUG('f', "virtSect %d is too large (>= %d)\n", virtSect, numSectors);
        return NULL;
    }

    int physBlock = virtSect / NumIndirect; // NumIndirect entries per block
    int blockIndex = virtSect % NumIndirect;

    ASSERT(physBlock < (int)NumDirect);
    ASSERT(indirectBlocks[physBlock] != NULL);

    int *physSect = &indirectBlocks[physBlock][blockIndex];

    return physSect;
}
//----------------------------------------------------------------------
// Give a mapping from file logical block (sector) number to the physical sector number
// The name of this function is confusing, not chosen correctly.
//----------------------------------------------------------------------

int FileHeader::getVirtualSector(int virtSect) {
    int *physSect = sectorMap(virtSect);
    ASSERT(physSect);

    DEBUG('F', "virt %d maps to phys %d\n", virtSect, *physSect);
    return *physSect;
}

//----------------------------------------------------------------------
// Setup  a mapping from file logical block (sector) number to the physical sector number
//  sectValue is the physical sector number
//----------------------------------------------------------------------

void FileHeader::setVirtualSector(int virtSect, int sectValue) {
    int *physSect = sectorMap(virtSect);
    ASSERT(physSect);
    ASSERT(*physSect == -1);

    *physSect = sectValue;
}

//----------------------------------------------------------------------
//Extend the file size from current numBytes to newNumBytes
//For simplificity, i would recommend that the file size is extended by a fixed size for each increment
//for example, choose the increment size = one that is handled by 1 indrect pointer.
//  Object freeMap maintains a set of free physical sectors. Use that to allocate physical sectors needed. 
//----------------------------------------------------------------------


void FileHeader::Extend(int newNumBytes, BitMap *freeMap) {
    DEBUG('F', "Extending file to %d bytes from %d\n", newNumBytes, numBytes);

    if (newNumBytes <= numBytes) {
        DEBUG('f', "Attempting to shorten file, ignoring\n");
        return;
    }
    if (newNumBytes > MaxFileSize) {
        DEBUG('F', "%d longer than %d, using MaxFileSize\n", newNumBytes, MaxFileSize);
        newNumBytes = MaxFileSize;
    }

    int newNumSectors;

/// code removed. Convert #bytes needed to #sector needed.
    ASSERT(newNumSectors >= numSectors);
    // if (newNumSectors == numSectors) we have enough space allocated; just return

//code removed
}

//----------------------------------------------------------------------
// FileHeader::Allocate
// 	Initialize a fresh file header for a newly created file.
//	Allocate data blocks for the file out of the map of free disk blocks.
//	Return FALSE if there are not enough free blocks to accomodate
//	the new file.
//
//	"freeMap" is the bit map of free disk sectors
//	"fileSize" is the bit map of free disk sectors
//----------------------------------------------------------------------

bool
FileHeader::Allocate(BitMap *freeMap, int fileSize)
{ 
    numBytes = fileSize;
    numSectors  = divRoundUp(fileSize, SectorSize);
    int numBlocks = divRoundUp(numSectors, NumIndirect);
    if (numBlocks > NumDirect) {
        DEBUG('f', "File will not fit in header\n");
        return FALSE;
    }
    DEBUG('F', "allocating %d bytes in %d sectors (%d blocks)\n", numBytes, numSectors, numBlocks);

    if (freeMap->NumClear() < numSectors + numBlocks)
	return FALSE;		// not enough space

    for (int i = 0; i < numBlocks; i++) {
        ASSERT(indirectSectors[i] == -1);
        ASSERT(indirectBlocks[i] == NULL);

        indirectSectors[i] = freeMap->Find();
        indirectBlocks[i] = new int[NumIndirect];
        for (int j = 0; j < NumIndirect; j++) {
            indirectBlocks[i][j] = -1;
        }
    }

    for (int i = 0; i < numSectors; i++)
	setVirtualSector(i, freeMap->Find());
    return TRUE;
}

//----------------------------------------------------------------------
// FileHeader::Deallocate
// 	De-allocate all the space allocated for data blocks for this file.
//
//	"freeMap" is the bit map of free disk sectors
//----------------------------------------------------------------------

void 
FileHeader::Deallocate(BitMap *freeMap)
{
    int numBlocks = divRoundUp(numSectors, NumIndirect);
    ASSERT(numBlocks <= NumDirect);

    for (int i = 0; i < numSectors; i++) {
	ASSERT(freeMap->Test(getVirtualSector(i)));  // ought to be marked!
	freeMap->Clear(getVirtualSector(i));
    }
    for (int i = 0; i < numBlocks; i++) {
        ASSERT(indirectSectors[i] != -1);
        ASSERT(freeMap->Test(indirectSectors[i]));
        freeMap->Clear(indirectSectors[i]);
    }
}

//----------------------------------------------------------------------
// FileHeader::FetchFrom
// 	Fetch contents of file header from disk. 
//
//	"sector" is the disk sector containing the file header
//----------------------------------------------------------------------

void
FileHeader::FetchFrom(int sector)
{
    DEBUG('F', "FetchFrom called\n");

    union {
        char *tempBuf;
        struct fileheaderrepr *header;
    };

    synchDisk->BeginTransaction();

    ASSERT(sizeof(fileheaderrepr) == SectorSize);
    tempBuf = new char[SectorSize];
    ASSERT(tempBuf);

    synchDisk->ReadSectorTrans(sector, tempBuf);

    numBytes = header->numBytes;
    numSectors = header->numSectors;
    memcpy(indirectSectors, header->indirectSectors, NumDirect * sizeof(int));

    delete tempBuf;

    ASSERT(sizeof(int[NumIndirect]) == SectorSize);
    int numBlocks = divRoundUp(numSectors, NumIndirect);
    ASSERT(numBlocks <= NumDirect);
    for (int i = 0; i < numBlocks; i++) {
        ASSERT(indirectSectors[i] != -1);
        if (indirectBlocks[i] != NULL) {
            printf("indirectBlocks[%d] = %p\n", i, indirectBlocks[i]);
        }
        ASSERT(indirectBlocks[i] == NULL);
        indirectBlocks[i] = new int[NumIndirect];
        ASSERT(indirectBlocks[i] != NULL);
        synchDisk->ReadSectorTrans(indirectSectors[i], (char*)indirectBlocks[i]);
    }

    synchDisk->EndTransaction();
}

//----------------------------------------------------------------------
// FileHeader::WriteBack
// 	Write the modified contents of the file header back to disk. 
//
//	"sector" is the disk sector to contain the file header
//----------------------------------------------------------------------

void
FileHeader::WriteBack(int sector)
{
    DEBUG('F', "WriteBack called\n");

    union {
        struct fileheaderrepr *header;
        char *tempBuf;
    };

    synchDisk->BeginTransaction();

    ASSERT(sizeof(struct fileheaderrepr) == SectorSize);
    tempBuf = new char[SectorSize];
    ASSERT(tempBuf);

    header->numBytes = numBytes;
    header->numSectors = numSectors;
    memcpy(header->indirectSectors, indirectSectors, NumDirect * sizeof(int));

    synchDisk->WriteSectorTrans(sector, tempBuf); 

    delete tempBuf;

    ASSERT(sizeof(int[NumIndirect]) == SectorSize);
    int numBlocks = divRoundUp(numSectors, NumIndirect);
    ASSERT(numBlocks <= NumDirect);
    for (int i = 0; i < numBlocks; i++) {
        ASSERT(indirectSectors[i] != -1);
        ASSERT(indirectBlocks[i] != NULL);
        synchDisk->WriteSectorTrans(indirectSectors[i], (char*)indirectBlocks[i]);
    }

    synchDisk->EndTransaction();
}

//----------------------------------------------------------------------
// FileHeader::ByteToSector
// 	Return which disk sector is storing a particular byte within the file.
//      This is essentially a translation from a virtual address (the
//	offset in the file) to a physical address (the sector where the
//	data at the offset is stored).
//
//	"offset" is the location within the file of the byte in question
//----------------------------------------------------------------------

int
FileHeader::ByteToSector(int offset)
{
    return(getVirtualSector(offset / SectorSize));
}

//----------------------------------------------------------------------
// FileHeader::FileLength
// 	Return the number of bytes in the file.
//----------------------------------------------------------------------

int
FileHeader::FileLength()
{
    return numBytes;
}

//----------------------------------------------------------------------
// FileHeader::Print
// 	Print the contents of the file header, and the contents of all
//	the data blocks pointed to by the file header.
//----------------------------------------------------------------------

void
FileHeader::Print()
{
    int i, j, k;
    char *data = new char[SectorSize];

    printf("FileHeader contents.  File size: %d.  File blocks:\n", numBytes);
    for (i = 0; i < numSectors; i++)
	printf("%d ", getVirtualSector(i));
    printf("\nIndirect block sectors:\n");
    j = divRoundUp(numSectors, NumIndirect);
    for (i = 0; i < j; i++) {
        printf("%d ", indirectSectors[i]);
    }
    printf("\nFile contents:\n");
    for (i = k = 0; i < numSectors; i++) {
	synchDisk->ReadSector(getVirtualSector(i), data);
        for (j = 0; (j < SectorSize) && (k < numBytes); j++, k++) {
	    if ('\040' <= data[j] && data[j] <= '\176')   // isprint(data[j])
		printf("%c", data[j]);
            else
		printf("\\%x", (unsigned char)data[j]);
	}
        printf("\n"); 
    }
    delete [] data;
}
