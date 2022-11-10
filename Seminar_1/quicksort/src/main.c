#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/quicksort.h"


/* ---------------------------------------------------------
 * C program to run quicksort algorithm on input of random
 * numbers retrieved from random_numbers.txt
 * --------------------------------------------------------- */
int main(void)
{
    int collection_size;
    FILE *inputfile;

    srand(time(NULL));

    printf("\nEnter collection size >> ");
    scanf("%d", &collection_size);

    printf("\n\nRunning benchmark on collection size of %d ...\n\n", collection_size);

    int arr[collection_size];
    int reference_arr[collection_size];
    inputfile = fopen("random_numbers.txt", "r");

    if(inputfile == NULL)
    {
        printf("Error reading file. Make sure 'random_numbers.txt' is available for benchmarking purposes ..\n");
        exit (0);
    }

    /* Read numbers from file into integer array, then save array to separate array
     * that will not be changed, and only used for resetting the sorted array */
    for (int i = 0; i < collection_size - 1; i++) fscanf(inputfile, "%d", &arr[i]);
    for (int i = 0; i < collection_size - 1; i++) reference_arr[i] = arr[i];

    double average_first = first_quicksort(arr, reference_arr, collection_size);
    double average_random = random_quicksort(arr, reference_arr, collection_size);
    double average_median_three = median_three_quicksort(arr, reference_arr, collection_size);

    printf("\n\nPivot element: Median of three\nExecution time for collection size of %d: %.16f\n", collection_size, average_median_three);
    printf("\n\nPivot element: Random\nExecution time for collection size of %d: %.16f\n", collection_size, average_random);
    printf("\n\nPivot element: First\nExecution time for collection size of %d: %.16f\n", collection_size, average_first);

    fclose(inputfile);
    return 0;
}

