#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

int p_first(int *arr, int L, int H);
int p_median(int* arr, int L, int H);
int p_random(int* arr, int p, int r);
void r_qsort(int P_TYPE, int *arr, int L, int H);
void i_qsort(int P_TYPE, int *arr, int L, int H);
int p_type(int *arr, int L, int H, int P_TYPE);
void swap(int *x, int *y);

#endif