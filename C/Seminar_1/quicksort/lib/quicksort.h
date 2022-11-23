#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

long median_pivot(int* arr, int L, int H);
long random_pivot(int* arr, int L, int H);
long p_type(int *arr, int L, int H, int P_TYPE);
long partition(int* arr, int L, int H, int P_TYPE);
void r_qsort(int P_TYPE, int *arr, int L, int H);
void i_qsort(int P_TYPE, int *arr, int L, int H);
void swap(int *x, int *y);

#endif