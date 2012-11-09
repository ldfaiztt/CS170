#ifndef USEROPENFILE_H
#define USEROPENFILE_H

class UserOpenFile {

    public:
        char* fileName;
        int indexInSysOpenFileList;
        int currOffsetInFile;
};

#endif // USEROPENFILE_H
