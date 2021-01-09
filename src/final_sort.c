#include <stdio.h>
#include "sorting_algorithims.h"
#include "read_write_file.h"

int selection_of_algorithims();

int main()
{
    int *array;
    int n;
    FILE * file;
    file = fopen("data_test.txt", "rb");
    fscanf(file, "%d", &n);
    array = file_read();


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
