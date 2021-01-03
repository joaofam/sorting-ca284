#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if(argc<2){
		printf("Error: Insufficent Command Line Arguements.\n");
		exit(1);
	}
	for(int i=0;i<strlen(argv[1]);i++){
		if(!(isdigit(argv[1][i]))){
			printf("Error: No non-digits permitted.\n");
			exit(1);
		}
	}

	int x = atoi(argv[1]);
	int i;
	FILE *fileptr;
	fileptr = fopen("data_test.txt", "w");
	srand(time(0));

	for(i=0;i<x;i++){
		fprintf(fileptr, "%d\n", rand());
	}
	fclose(fileptr);	
	return 0;
}

/* source - https://stackoverflow.com/questions/37613522/generating-random-numbers-in-c-and-writing-it-to-a-text-file*/
