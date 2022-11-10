#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER
#include <time.h>

int partition(int arr[], int L, int H);
void recursive_quicksort(int arr[], int L, int H);
void swap(int *x, int *y);
int medianthree(int a, int b, int c);
double median_three_quicksort(int *arr, int *unsorted_arr, int collection_size);
double first_quicksort(int *arr, int *unsorted_arr, int collection_size);
double random_quicksort(int *arr, int *unsorted_arr, int collection_size);

#endif