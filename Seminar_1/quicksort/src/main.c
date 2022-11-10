#include <stdio.h>
#include <stdlib.h>
#include "../lib/quicksort.h"
#define MAX 1000

/* ---------------------------------------------------------
 * C program to run quicksort algorithm on input of random
 * numbers retrieved from random_numbers.txt
 * --------------------------------------------------------- */
int main(void)
{
    FILE *inputfile;
    int arr[MAX];
    inputfile = fopen("random_numbers.txt", "r");
    for (int i = 0; i < MAX; i++) fscanf(inputfile, "%d", &arr[i]);

    /* Select rightmost element as pivot */
    int pivot = MAX - 1;

    recursive_quicksort(arr, 0, pivot);
    for (int i = 0; i < MAX; ++i) printf("%d  ", arr[i]);
    printf("\n");
    return 0;
}
