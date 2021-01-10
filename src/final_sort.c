#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#include "sorting_algorithims.h"
#include "read_write_file.h"

int selection_of_dataset();
int sort_dataset(int datasort, int * array, int n);

int selection_of_algorithims();
void sort_choice(int sort, int *array, int n);

int main()
{
    int *array;
    int n;
    FILE * file;
    file = fopen("data_test.txt", "rb");
    fscanf(file, "%d", &n);
    array = file_read();

    int datasort = selection_of_dataset();
    int sort = selection_of_algorithims();
    
    clock_t start = clock();
    sort_choice(sort, array, n);
    clock_t end = clock();
    sort_dataset(datasort, array, n);

    double execution_time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    printf("\nExecution time is %fms.\n\n", execution_time);

    file_write(array, n);
    return 0;
}
int selection_of_dataset()
{
    int datasort;
    printf("Select dataset of choice:\n"
          " - 1 - Ascending Sort\n"
          " - 2 - Descending Sort\n"
          " - 3 - Random Sort\n");
    scanf("%d", &datasort);
    return datasort;
}


int sort_dataset(int datasort, int * array, int n)
{
    if(datasort == 1)
    qsort(array, n, sizeof(int), compare_ints);
   else if(datasort == 2)
    qsort(array, n, sizeof(int), descending_ints);
  else if(datasort == 3)
    return 0;
  else{
    printf("Not a valid number for dataset selection.\n");
		exit(1);
  }

}
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

void sort_choice(int sort, int *array, int n)
{
    if(sort == 1)
		selection_sort(array, n);
	else if(sort == 2)
		insertion_sort(array, n);
    else if(sort == 3)
		radixsort(array, n);
	else{
		printf("Not a valid number for algorithim selection.\n");
		exit(1);
	}
}
