#include <stdio.h>
#include "read_write_file.h"

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
