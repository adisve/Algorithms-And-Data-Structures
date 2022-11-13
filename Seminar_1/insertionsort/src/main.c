#include <stdio.h>
#include <stdlib.h>
#include "../lib/measurement.h"

#define MAX     1000000
#define CYCLES  10


/* ---------------------------------------------------------
 * C program to calculate average runtime on Insertion Sort,
 * on an array of dynamic input size, given by the user.
 * --------------------------------------------------------- */
int main(void)
{
        FILE *inputfile;
        int collection_size;
        
        printf("\nEnter collection size >> ");
        scanf("%d", &collection_size);
        while (collection_size > MAX){
                printf("\nInput too big. Try a number below %d\n", MAX);
                printf("\nEnter collection size >> ");
                scanf("%d", &collection_size);
        }
        int arr[collection_size];
        int reference_arr[collection_size];
        inputfile = fopen("random_numbers.txt", "r");

        if(inputfile == NULL)
        {
                printf("Error reading file. Make sure 'random_numbers.txt' is available for benchmarking purposes ..\n");
                exit (0);
        }

        printf("\n\nRunning Insertion Sort benchmark on collection of size %d, for %d cycles ...\n\n", collection_size, CYCLES);

        

        /* Read numbers from file into integer array */
        for (int i = 0; i < collection_size; i++) fscanf(inputfile, "%d", &arr[i]);
        fclose(inputfile);

        /* 'Clone' array to a separate array that will not be changed, and only used
        * for re-setting the eventually sorted array */
        for (int i = 0; i < collection_size; i++) reference_arr[i] = arr[i];

        measure_insertionsort(arr, reference_arr, collection_size);
}