#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/measurement.h"

#define MAX       1000000
#define RECURSIVE 0
#define ITERATIVE 1

/* ---------------------------------------------------------
 * C program to calculate average runtime on Quick Sort,
 * on an array of dynamic input size, given by the user.
 * --------------------------------------------------------- */
int main(void)
{
    FILE *inputfile;
    int collection_size;
    srand(time(NULL));
    

    printf("\nEnter collection size >> ");
    scanf("%d", &collection_size);
    while (collection_size > MAX){
        printf("\nInput too big. Try a number below %d\n", MAX);
        printf("\nEnter collection size >> ");
        scanf("%d", &collection_size);
    }
    printf("\n\nRunning benchmark on collection size of %d ...\n\n", collection_size);

    int *arr = malloc(sizeof(int) * collection_size);
    int *reference_arr = malloc(sizeof(int) * collection_size);
    inputfile = fopen("random_numbers.txt", "r");

    if(inputfile == NULL)
    {
        printf("Error reading file. Make sure 'random_numbers.txt' is available for benchmarking purposes ..\n");
        return EXIT_FAILURE;
    }


    /* Read numbers from file into integer array */
    for (int i = 0; i < collection_size; i++) fscanf(inputfile, "%d", &arr[i]);
    fclose(inputfile);
    /* 'Clone' array to a separate array that will not be changed, and only used
     * for re-setting the eventually sorted array */
    for (int i = 0; i < collection_size; i++) reference_arr[i] = arr[i];


    /* Measurements for quick sort using RECURSIVE quick sort algorithm */
    measure_recursive_quicksort(arr, reference_arr, &collection_size, RECURSIVE);


    /* Measurements for quick sort using recursive quick sort algorithm */
    measure_iterative_quicksort(arr, reference_arr, &collection_size, ITERATIVE);
    
    free(arr);
    free(reference_arr);
    return EXIT_SUCCESS;
}