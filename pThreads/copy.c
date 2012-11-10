/*
 *  ============================================================================
 *   Name        : copy.c
 *    Author      : Marko Martinovi.
 *     Description : Copy input file into output file
 *     http://www.techytalk.info/linux-system-programming-open-file-read-file-and-write-file/
 *      ============================================================================
 *       */
 
#include <stdio.h>
#include <fcntl.h>
 
#define BUF_SIZE 8192
 
void main(int argc, char* argv[]) {
 
    int input_fd, output_fd;    /* Input and output file descriptors */
    int ret_in, ret_out;    /* Number of bytes returned by read() and write() */
    char buffer[BUF_SIZE];      /* Character buffer */
 
    /* Are src and dest file name arguments missing */
    if(argc != 3){
        printf ("Usage: copy file1 file2\n");
        return;
    }
 
    /* Create input file descriptor */
    input_fd = open (argv [1], O_RDONLY);
    if (input_fd == -1) {
            printf ("Error in openning the input file\n");
            return;
    }
 
    /* Create output file descriptor */
    output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if(output_fd == -1){
            printf ("Error in openning the output file\n");
        return;
    }
 
    /* Copy process */
    while((ret_in = read (input_fd, &buffer, BUF_SIZE)) > 0){
            ret_out = write (output_fd, &buffer, ret_in);
            if(ret_out != ret_in){
                /* Write error */
                printf("Error in writing\n");
            }
    }
 
    /* Close file descriptors */
    close (input_fd);
    close (output_fd);
 
}
