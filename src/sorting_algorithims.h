/* 3 algorithims */

void display(int array[], int n);

void swap(int *x, int *y);
void selection_sort(int *array, const int n);

void insertion_sort(int *a, int n);

int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);

int compare_ints(const void *a, const void *b);
int descending_ints(const void *a, const void* b);

/* Swap function to be added to Selection */
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

/* Selection sort algorithim */
void selection_sort(int* array, const int n)
{
	int i, j;
	int min;
    
    /* for loop to search for the minimum element */
	for (i=0; i<n-1; i++){
        min = i;
        for (j=i+1; j<n; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        /* swap function to swap the minimum element with the first element */
        swap(&array[i], &array[min]);
    }
}

/* Insertion sort algorithim */
void insertion_sort(int *array, const int n)
{
    int i,j, key;
    for(i=1; i<n; ++i)
    {
        key=array[i];
        j=i-1;

        /* elements that are greater than they key are moved 
        from their current possition to one position ahead */
        while ((j >= 0) && (key < array[j])){
            array[j+1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }
}

/* function to obtain the max value in the array */
int getMax(int array[], int n) 
{ 
    int i;
    int max = array[0]; 
    for (i=1; i<n; i++) 
        if (array[i] > max) 
            max = array[i]; 
    return max; 
} 
  
void countSort(int array[], int n, int exp) 
{ 
    int output[n];
    int i, count[10] = { 0 }; 
  
    for (i=0; i<n; i++) 
        count[(array[i] / exp) % 10]++; 
  
    for (i=1; i<10; i++) 
        count[i] += count[i-1]; 
  
    for (i=n-1; i>=0; i--) { 
        output[count[(array[i] / exp) % 10] - 1] = array[i]; 
        count[(array[i] / exp) % 10]--; 
    } 
  
    for (i=0; i<n; i++) 
        array[i] = output[i]; 
} 
   
void radixsort(int array[], int n) 
{ 
    int exp;
    int max = getMax(array, n); 
  
    for (exp=1; max / exp > 0; exp *= 10) 
        countSort(array, n, exp); 
} 

void display(int array[], int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("%d ", array[i]);
    /* New line add */
	printf("\n");
	}
}

/* DataSets */

int compare_ints(const void *a, const void *b)
{
const int *da = (const int *) a;
const int *db = (const int *) b;

return (*da > *db) - (*da < *db);
}

int descending_ints(const void *a, const void * b)
{
    const int *da = (const int *) a;
    const int *db = (const int *) b;

    return (*da < *db) - (*da > *db);
}

/* Sources */
/* --------*/
/* Selection Sort - https://www.zentut.com/c-tutorial/c-selection-sort/ */
/*Insertion Sort - https://www.zentut.com/c-tutorial/insertion-sort-in-c/ */
/* Radix Sort -  */