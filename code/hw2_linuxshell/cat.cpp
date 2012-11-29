/*
 *  ============================================================================
 *   Name        : copy.c
 *    Author      : Marko Martinovi.
 *     Description : Copy input file into output file
 *     http://www.techytalk.info/linux-system-programming-open-file-read-file-and-write-file/
 *      ============================================================================
 *       */
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {

/* Are src and dest file name arguments missing */
   if(argc != 2){
        printf ("No file was found\n");
        return(1);
    }


    /* Open file */
    ifstream myfile;
    myfile.open(argv[1]);
    string line;
    /* Check if file is open*/
    if (myfile.is_open())
    {
       /* Output file to comand window*/
        while ( myfile.good() )
        {
        getline (myfile ,line);
        cout << line << endl;
        }
        cout << "Hello" << endl;

       /* Close file descriptor */
        myfile.close();
    }
    else cout << "Can't open file \n";

    return 0;
}
