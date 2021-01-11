/* sorting_algorithims is a header file which contains
 all three algorithims used to sort data. It also contains
at the bottom datasets which are used to sort data in a specific order*/

void display(int array[], int n);

void swap(int *x, int *y);
void selection_sort(int *array, const int n);

void insertion_sort(int *a, int n);

int getMax(int array[], int n);
void countSort(int array[], int n, int exp);
void radixsort(int array[], int n);

int ascending_order(const void *x, const void *y);
int descending_order(const void *x, const void* y);
void random_order(int *array, int n);

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
    for(i=1; i<n; ++i){
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

/* Radix Sort*/
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

/* countSort function to count sort the array by the digit (exp)*/
void countSort(int array[], int n, int exp) 
{ 
    /* same line as read_write_file to allocate memory and allow for larger data */
    int * output = malloc(sizeof(int) * n);
    int i, count[10] = { 0 }; 
    
    /* use count to gather all occurances */
    for (i=0; i<n; i++){
        count[(array[i] / exp) % 10]++; 
    }
    /* for loop to change count that now 
    keeps position of the digit*/
    for (i=1; i<10; i++){
        count[i] += count[i-1]; 
    }
    /* for loop for output array creation */
    for (i=n-1; i>=0; i--){ 
        output[count[(array[i] / exp) % 10] - 1] = array[i]; 
        count[(array[i] / exp) % 10]--; 
    } 
    /* output array copied to array[] so array[] 
    has the sorted numbers to their current digit */
    for (i=0; i<n; i++){
        array[i] = output[i]; 
    }
} 

/* Main Radix sort function */
void radixsort(int array[], int n) 
{ 
    int exp;
    /*Get max number */
    int max = getMax(array, n); 
    
    /* countSort function is used for every digit. 
    exp is passed and i is the current digit int */
    for (exp=1; max / exp > 0; exp *= 10){
        countSort(array, n, exp); 
    }
} 
/* function to output all elements of array */
void display(int array[], int n)
{
	int i;
	for(i=0; i<n; i++){
		printf("%d ", array[i]);
    /* New line add */
	printf("\n");
	}
}

/* DataSets */

/* Dataset to sort array in descending order */
int ascending_order(const void *x, const void *y)
{
    const int *dx = (const int *) x;
    const int *dy = (const int *) y;

    return (*dx > *dy) - (*dx < *dy);
}

/* Dataset to sort array in descending order */
int descending_order(const void *x, const void * y)
{
    const int *dx = (const int *) x;
    const int *dy = (const int *) y;

    return (*dx < *dy) - (*dx > *dy);
}

/* Dataset to sort array in random order */
void random_order(int *array, int n)
{
    int i;
    if (n>1) {
        for (i=0; i<n-1; i++) {
          int j = i + rand() / (RAND_MAX / (n-i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

/* Sources */
/* --------*/
/* Selection Sort - https://www.zentut.com/c-tutorial/c-selection-sort/ */
/* Insertion Sort - https://www.zentut.com/c-tutorial/insertion-sort-in-c/ */
/* Radix Sort - https://www.geeksforgeeks.org/radix-sort/ */