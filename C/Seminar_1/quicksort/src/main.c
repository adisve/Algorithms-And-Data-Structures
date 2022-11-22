#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/measurement.h"

#define MAX       1000000
#define RECURSIVE 0
#define ITERATIVE 1

int error();

/* ---------------------------------------------------------
 * C program to calculate average runtime on Quick Sort,
 * on an array of dynamic input size, given by the user.
 * --------------------------------------------------------- */
int main(void)
{
    FILE *inputfile;
    int COLLECTION_SIZE;
    srand(time(NULL));
    
    printf("\nEnter collection size >> ");
    scanf("%d", &COLLECTION_SIZE);
    while (COLLECTION_SIZE > MAX){
        printf("\nInput too big. Try a number below %d\n", MAX);
        printf("\nEnter collection size >> ");
        scanf("%d", &COLLECTION_SIZE);
    }
    
    int *arr = malloc(sizeof(int) * COLLECTION_SIZE);
    
    inputfile = fopen("random_numbers.txt", "r");

    if(inputfile == NULL) return error();


    /* Read numbers from file into integer array */
    for (int i = 0; i < COLLECTION_SIZE; i++) fscanf(inputfile, "%d", &arr[i]);
    fclose(inputfile);
    printf("\n\nRunning benchmark on collection size of %d ...\n\n", COLLECTION_SIZE);


    /* Measurements for quick sort using RECURSIVE quick sort algorithm */
    measure_r_qsort(arr, &COLLECTION_SIZE, RECURSIVE);


    /* Measurements for quick sort using recursive quick sort algorithm */
    measure_i_qsort(arr, &COLLECTION_SIZE, ITERATIVE);
    
    return EXIT_SUCCESS;
}

int error()
{
    printf("Error reading file. Make sure 'random_numbers.txt' is available for benchmarking purposes ..\n");
    return EXIT_FAILURE;
}