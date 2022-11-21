#include <stdio.h>
#include <stdlib.h>
#include "../lib/measurement.h"

#define MAX 1000000

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/* ---------------------------------------------------------
 * C program to calculate average runtime on Binary Search,
 * on an array of dynamic input size, given by the user.
 * --------------------------------------------------------- */
int main(void)
{
        int collection_size;
        int element;
        FILE *inputfile;
        printf("\nEnter collection size >> ");
        scanf("%d", &collection_size);

        while (collection_size > MAX) 
        {
                printf("\nCollection size must be less than %d", MAX);
                scanf("%d", &collection_size);
        }

        printf("\nElement to search for >> ");
        scanf("%d", &element);

        int arr[collection_size];
        inputfile = fopen("random_numbers.txt", "r");

        if(inputfile == NULL)
        {
                printf("Error reading file. Make sure 'random_numbers.txt' is available for benchmarking purposes ..\n");
                exit (0);
        }

        /* Read numbers from file into integer array */
        for (int i = 0; i < collection_size-1; i++) fscanf(inputfile, "%d", &arr[i]);
        /* Sort array before performing binary search */
        qsort(arr, collection_size-1, sizeof(int), cmpfunc);

        measure_binarysearch(arr, collection_size, element);

        fclose(inputfile);

        return 0;
}