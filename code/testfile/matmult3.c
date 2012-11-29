/* matmult3.c 
 *    Test program to do matrix multiplication on large arrays.
 *
 *    Intended to stress virtual memory system.
 *
 *    Ideally, we could read the matrices off of the file system,
 *	and store the result back to the file system!
 */

#include "syscall.h"

#define Dim	12	/* sum total of the arrays fits
			 * physical memory 
			 */

int A[Dim][Dim];
int B[Dim][Dim];
int C[Dim][Dim];


int
main()
{
    int i, j, k;
    char d;

    
    Write("MM 1\n", 5, ConsoleOutput);
    for (i = 0; i < Dim; i++)		/* first initialize the matrices */
	for (j = 0; j < Dim; j++) {
	     A[i][j] = i;
	     B[i][j] = j;
	     C[i][j] = A[i][j] * B[i][j];
	}



    d= C[11][11] % 10  + '0';
    Write("@11,11: ", 8, ConsoleOutput);
    Write(&d, 1, ConsoleOutput);
    Write("\n:", 1, ConsoleOutput);
    Exit(0);		/* and then we're done */
}
