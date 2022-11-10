#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

int partition(int *arr, int L, int H);
void quicksort(int *arr, int L, int H, int type);
void swap(int *x, int *y);

#endif