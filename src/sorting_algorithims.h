/* 3 algorithims */

void swap(int *x, int *y);
void selection_sort(int *a, const int n);
void display(int array[], int size);

void insertion_sort(int *a, const int size);

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void selection_sort(int* array, const int size)
{
	int i, j;
	int min;

	for (i = 0; i < size - 1; i++){
        min = i;
        for (j = i + 1; j < size; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}

void insertion_sort(int *array, const int n)
{
	int i, j, k;
	for(i=0;i<n;i++){
		k = array[j];
		j = i - 1;
		while ((j >= 0) && (k < array[j]))
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = k;
    }
}

 /* This display function is utilized to print each element of the array */
void display(int array[], int size)
{
	int i;
	for(i=0;i<size;i++){
		printf("%d ", array[i]);
	printf("\n");
	}
}
