#ifndef QUICKSORT_HEADER
#define QUICKSORT_HEADER

int partition(int *arr, int L, int H);
void quicksort(int *arr, int L, int H, int type);
void swap(int *x, int *y);
int medianthree(int a, int b, int c);
double median_three_quicksort(int *arr, int *reference_arr, int collection_size, int type);
double first_quicksort(int *arr, int *reference_arr, int collection_size, int type);
double random_quicksort(int *arr, int *reference_arr, int collection_size, int type);

#endif