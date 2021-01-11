#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/* This a Rundem number generator which uses a command
 line arguement number to output a list (from 1 to command line arg)
  of random numbers to a text file called data_test.txt */

int main(int argc, char *argv[])
{
	/* Output error if no command line arguement is put in */
	if(argc<2){
		printf("Error: Insufficent command line aguements.\n");
		exit(1);
	}
	/* Output error if non-number is inputted */
	for(int i=0; i<strlen(argv[1]); i++){
		if(!(isdigit(argv[1][i]))){
			printf("Error: No non-digits permitted.\n");
			exit(1);
		}
	}
	/* x is the first index command line arguement as an int (atoi) */
	int x = atoi(argv[1]);
	int i;
	FILE *file;
	/* open data_text.txt and add it to variable file */
	file = fopen("data_test.txt", "wb");
	srand(time(0)); /* used to initialize the pseudo-random number generator by passing the argument seed. */

	/*fprtinf utilized to output data into a file */
	/* add command line arguement as the first line of data_set.txt for future use */
	fprintf(file, "%d\n", x);

	for(i=0; i<x; i++){
		fprintf(file, "%d\n", rand()); /* return random numbers to data_set.txt */
	}
	/* stops stream and gets rid of any unwanted data in streams buffer */
	fclose(file);	
	return 0;
}

/* source - https://stackoverflow.com/questions/37613522/generating-random-numbers-in-c-and-writing-it-to-a-text-file */
/* soruce - https://www.codingunit.com/c-reference-stdlib-h-function-srand-initialize-random-number-generator */
