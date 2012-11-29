#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#define GetCurrentDir getcwd

using namespace std;

void ls();
void exit();

int main()
{

	int i, var;
	int input_fd = 0;
	int pid;
	int compareLimit = 100; // For string comparison

	string cinput;
	char input[100];
	printf("Starting shell \n");
	while (true){

		cin.getline (input,100);

		if ((strncmp(input, "ls", compareLimit) == 0) )
		{
			pid=fork();
				if(pid==0)
				{
					ls();
				}
				else if (pid > 0)
				{
					wait();
				}

		}
		else if (strncmp(input, "exit", compareLimit) == 0)
		{

			return(0);
		}

		else if(strncmp(input, "cat", 3) == 0 && (input[3]==' ' || input[3]=='\0'))
		{
			if(input[3] ==  '\0' || (input[3] ==' ' && input[4] =='\0')){
				printf("Invalid argument, use cat <arg>\n");
			}else{

				char arg[96];

				int i = 0;
				while(input[i] != '\0' && (i < 96))
				{
					arg[i] = input[i+4];
					i++;
				}

				pid=fork();
				if(pid==0)
				{
					execlp("./main",input,arg,NULL);

				}
				else if (pid > 0)
				{
					wait();
				}
			}
		}else if(strncmp(input, "exit", compareLimit) == 0){
			printf("Exiting");
			return(0);
		}

		else{
			printf("Undefined comand: %s \n", input);
		}

	}

}

void ls()

{
	DIR *dir;
	struct dirent *ent;

	char cCurrentPath[FILENAME_MAX];

 	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    	{

     	}

	printf ("The current working directory is %s", cCurrentPath);

    	dir = opendir (cCurrentPath);
	if (dir != NULL) {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL) {
    			if(ent->d_name  != ".."){

    				printf ("%s\n", ent->d_name);
				}
 		}
  		closedir (dir);
	} else {
  		/* could not open directory */
  		perror ("");

	}
}


void exit()
{
	cout<< "exit" << endl;

}
