#ifndef MEASUREMENT_HEADER
#define MEASUREMENT_HEADER

void measure_r_qsort(long *arr, long* COLLECTION_SIZE, int type);
void measure_i_qsort(long *arr, long* COLLECTION_SIZE, int type);
void printresult(long COLLECTION_SIZE, double avg_first, double avg_median, double avg_random, int type);

#endif