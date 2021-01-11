#include <stdio.h>
#include <stdlib.h>

int * file_read()
{
    /* pointer created to access Files */
    FILE * file;

    /* open data_test.txt */
    file = fopen("data_test.txt", "rb");

    /* size_t is used as it deal with any negative int */
    size_t read;
    char * line = NULL;
    size_t line_len = 0;

    int n;
    /*fscanf is used to read in files */
    fscanf(file, "%d", &n);
    /*use malloc to allocate memory and return a pointer and access large amounts of data*/
    int * array = malloc(sizeof(int) * n);

    /* for loop to put int into an array*/
    for (int i=0; i<n; i++)
    {
        fscanf(file, "%d", &array[i]);
    }
    /* exit stream and flush all buffers*/
    fclose(file);
    return array;
}

/* Function to write outputs to a text file called sorted_data.txt */
void file_write(int array[], int n)
{
    FILE *file;
    file = fopen("sorted_data.txt", "wb");
    for (int  =0; i<n; i++){
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
}


/* https://stackoverflow.com/questions/43102842/reading-integers-from-txt-file-in-c */
/* https://stackoverflow.com/questions/18597685/how-to-write-an-array-to-file-in-c */
/* https://stackoverflow.com/questions/20378430/reading-numbers-from-a-text-file-into-an-array-in-c */