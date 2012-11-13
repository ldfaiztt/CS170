#include "syscall.h"

int main() {

    OpenFileId f0;
    char usr_buffer[256];

    Create( "TESTOUTPUTFILE" );
    f0 = Open( "TESTOUTPUTFILE" );
    Write( "Hello, World!\n", 14, f0 );
    Close( f0 );
}
