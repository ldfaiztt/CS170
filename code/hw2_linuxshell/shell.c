#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 40

int main() {
	fflush(stdout);
	printf("\nShell launched\n");
	int i;
	int inputFileDescriptor = 0;
	int pid;
	int compareLimit = 100;// For string comparison
	char buffer[BUFFER_SIZE];
	while (1) {
		write(1, ">> ", 4);
		i = 0;
		do {
			read(inputFileDescriptor, &buffer[i], 1);
		} while (buffer[i++] != '\n');
		buffer[--i] = '\0';
		// Exit
		if (strncmp(buffer, "exit", compareLimit) == 0) {
			write(1, "Shell terminated\n", 17);
			return 0;
		}
		//Cat <arg>
		else if (strncmp(buffer, "cat", 3) == 0	&& (buffer[3] == ' ' || buffer[3] == '\0')) {
			if (buffer[4] == '\0' || buffer[3] == '\0') {
				write(1, "Missing argument: cat <arg>\n", 29);
			} else {
				// Copying from buffer into catArg
				char catArg[BUFFER_SIZE];
				i = 0;
				while (buffer[i] != '\0' && (i != BUFFER_SIZE - 4)) {
					catArg[i] = buffer[i + 4];
					i++;
				}
				pid = fork();
				if (pid == 0) {
					execlp("cat", buffer, catArg, NULL);
				} else if (pid > 0) {
					wait();
					write(1, "\n", 1);
				}
			}
		} else if (strncmp(buffer, "ls", compareLimit) == 0) {
			pid = fork();
			if (pid == 0) {
				execlp("/bin/ls", buffer, NULL);
			} else if (pid > 0) {
				wait();
			}
		} else {
			write(1, "Shell: ", 8);
			write(1, &buffer, i);
			write(1, ": command not found...\n", 23);
		}

	}
	return 0;
}
