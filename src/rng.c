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
	FILE *file;
	file = fopen("data_test.txt", "wb");
	srand(time(0));

	fprintf(file, "%d\n", x);

	for(i=0;i<x;i++){
		fprintf(file, "%d\n", rand());
	}
	fclose(file);	
	return 0;
}

/* source - https://stackoverflow.com/questions/37613522/generating-random-numbers-in-c-and-writing-it-to-a-text-file*/
