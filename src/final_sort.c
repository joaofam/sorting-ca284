#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // for clock_t, clock()
#include <unistd.h>     // for sleep()
#include "sorting_algorithims.h" /* Call in header files */
#include "read_write_file.h"

/* Main C file where program is run and completed.
First the user must run rng.c where random data will be 
outputted to data_test.txt and then run this final_sort.c file
where he will they will be able to input an algorithim of
choice as well as a dataset of choice. Once both inputs are placed 
the program will display the time of sorting execution as well as 
place the sorted data into a text file called sorted_data.txt */

int selection_of_dataset();
int sort_dataset(int datasort, int * array, int n);

int selection_of_algorithims();
void sort_choice(int sort, int *array, int n);

int main()
{
    int *array;
    int n;
    int i;

    FILE * file;
    /* open data_test.txt where random data is located */
    file = fopen("data_test.txt", "rb");
    fscanf(file, "%d", &n);
    array = malloc(sizeof(int) * n);

    for (i=0; i<n; i++){
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);

    int datasort = selection_of_dataset();
    int sort = selection_of_algorithims();
    /* allow user to pick dataset and run dataset */
    sort_dataset(datasort, array, n); 
    /* clock function to calculate time of sorting */
    clock_t start = clock(); /* initiation of clock */
    /* allow user to input algorithim of choice and run algorithim */
    sort_choice(sort, array, n);
    clock_t end = clock(); /* end time since sorting is finalized */

    double execution_time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    
    printf("\nExecution time is %fms.\n\n", execution_time);
    /* storage from the heap using malloc is no longer needed so we return it */
    free(array);
    /* output results to sorted_data.txt */
    file_write(array, n);
    return 0;
}

/* Function to allow user to choose a dataset */
int selection_of_dataset()
{
    int datasort;
    printf("Select dataset of choice:\n"
          " - 1 - Ascending Sort\n"
          " - 2 - Descending Sort\n"
          " - 3 - Random Sort\n");
    if (scanf("%d", &datasort) != 1 ){ /* Only allow user to input numbers and output error if neither 1, 2 or 3 is inputted */
        printf("\nERROR: Inavlid Character Entered\n------\nPlease enter a valid number\n");
        exit(0);
  }
    return datasort;
}

/* Function to output user's input as a dataset*/
int sort_dataset(int datasort, int * array, int n)
{
  if(datasort == 1)
    qsort(array, n, sizeof(int), ascending_order);
  else if(datasort == 2)
    qsort(array, n, sizeof(int), descending_order);
  else if(datasort == 3)
    random_order(array, n);
	else{ /* print error if 1, 2 or 3 is not inputted */
		printf("Not a valid number for dataset selection.\n");
		exit(0);
  }
}

/* Function to allow user to pick algorithim of choice */
int selection_of_algorithims()
{
    int sort;        
    printf("Select algorithim of choice:\n"
            " - 1 - Selection Sort\n"
            " - 2 - Insertion Sort\n"
            " - 3 - Radix Sort\n");
    scanf("%d", &sort);
    return sort;
}

/* Function to output user's input as an algorithim*/
void sort_choice(int sort, int *array, int n)
{
  if(sort == 1)
		selection_sort(array, n);
	else if(sort == 2)
		insertion_sort(array, n);
  else if(sort == 3)
		radixsort(array, n);
	else{ /* If neither 1, 2 or 3 are inputted an error will be outputted */
		printf("Not a valid number for algorithim selection.\n");
		exit(0);
  }
}

/* source - https://stackoverflow.com/questions/26106531/how-do-i-only-accept-numbers-in-c-and-block-the-user-from-entering-letters-and-s*/
/* source - https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/ */
