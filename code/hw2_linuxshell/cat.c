#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 50

void main(int argc, char* argv[]) {
	int inputFileDescriptor;
	int inputReturnSize;
	int outputReturnSize;
	int i;
	char buffer[BUFFER_SIZE];

	// Create input file descriptor
	inputFileDescriptor = open(argv[1], O_RDONLY);
	if (inputFileDescriptor == -1) {
		printf("Error in opening the input file\n");
		return;
	}
	// Writing to consol
	while ((inputReturnSize = read(inputFileDescriptor, &buffer, BUFFER_SIZE)) > 0) {
		outputReturnSize = write(1, &buffer, inputReturnSize);
		write(1, "\n", 1);
		if (outputReturnSize != inputReturnSize) {
			printf("Error in writing\n");
		}
	}
	write(1, "\n", 1);
	// Close input file descriptors
	close(inputFileDescriptor);
}
