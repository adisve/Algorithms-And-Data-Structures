#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

int median_pivot(int* arr, int L, int H);
int random_pivot(int* arr, int L, int H);
int partition(int* arr, int L, int H, int P_TYPE);
void r_qsort(int P_TYPE, int *arr, int L, int H);
void i_qsort(int P_TYPE, int *arr, int L, int H);
int p_type(int *arr, int L, int H, int P_TYPE);
void swap(int *x, int *y);

#endif