#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

long median_pivot(long* arr, long L, long H);
long random_pivot(long* arr, long L, long H);
long p_type(int P_TYPE, long *arr, long L, long H);
long partition(int P_TYPE, long* arr, long L, long H);
void r_qsort(int P_TYPE, long *arr, long L, long H);
void i_qsort(int P_TYPE, long *arr, long L, long H);
void swap(long *x, long *y);

#endif