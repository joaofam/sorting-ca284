#include <stdio.h>
#include <stdlib.h>

int * file_read()
{
    FILE * file;

    file = fopen("data_test.txt", "rb");

    size_t read;
    char * line = NULL;
    size_t line_len = 0;

    int n;
    fscanf(file, "%d", &n);
    int * array = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);
    return array;
}
