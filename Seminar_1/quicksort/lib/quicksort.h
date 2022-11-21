#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

int partition_first(int *arr, int L, int H);
int partition_median(int* arr, int L, int H);
int partition_random(int* arr, int L, int H);
void recursive_quicksort(int pivot_type, int *arr, int L, int H);
void iterative_quicksort(int pivot_type, int *arr, int L, int H);
void swap(int *x, int *y);

#endif