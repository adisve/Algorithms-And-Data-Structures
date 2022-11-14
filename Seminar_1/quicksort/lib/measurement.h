#ifndef MEASUREMENT_HEADER
#define MEASUREMENT_HEADER

void measure_recursive_quicksort(int *arr, int *reference_arr, int* collection_size, int type);
void measure_iterative_quicksort(int *arr, int *reference_arr, int* collection_size, int type);
int setpivot(int type, int *arr, int collection_size);
void printresult(int collection_size, double average_rec_first, double average_rec_median_three, double average_rec_random, int type);

#endif