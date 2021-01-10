#include <stdio.h>
#include "sorting_algorithims.h"
#include "read_write_file.h"

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

    int sort = selection_of_algorithims();

    sort_choice(sort, array, n);

    file_write(array, n);
    return 0;
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


/* https://www.techiedelight.com/find-execution-time-c-program/ */