#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#include "math.h"
#include "measurement.h"

#define CYCLES  10
#define MEDIAN  0
#define FIRST   1
#define RANDOM  2
#define RECURSIVE 0
#define ITERATIVE 1



void measure_recursive_quicksort(int *arr, int *reference_arr, int* collection_size, int type)
{
        int pivottypes[3] = {0, 1, 2};
	clock_t end;
        clock_t begin;
        double average_first;
        double average_random;
        double average_median_three;
        size_t pivottypes_len = sizeof(pivottypes)/sizeof(pivottypes[0]);

        for (int i = 0; i < pivottypes_len; i++) {
                double avg_sum = 0;
                /* Execute quicksort for 10 cycles */
                for (int j = 0; j < CYCLES; j++)
                {
                        begin = clock();
                        recursive_quicksort(pivottypes[i], arr, 0, *collection_size);
                        end = clock();
                        double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
                        avg_sum += time_spent;
                        /* Reset sorted list to be old version */
                        for (int j = 0; j < *collection_size; j++) arr[j] = reference_arr[j];
                }
                
                switch (pivottypes[i]) {
                        case MEDIAN:
                                average_median_three = avg_sum / CYCLES;
                                break;
                        case FIRST:
                                average_first = avg_sum / CYCLES;
                                break;
                        case RANDOM:
                                average_random = avg_sum / CYCLES;
                                break;
                }
        }

        printresult(*collection_size, average_first, average_median_three, average_random, type);
}

void measure_iterative_quicksort(int *arr, int *reference_arr, int* collection_size, int type)
{
        int pivottypes[3] = {0, 1, 2};
        clock_t end;
        clock_t begin;
        double average_first;
        double average_random;
        double average_median_three;
        size_t pivottypes_len = sizeof(pivottypes)/sizeof(pivottypes[0]);

        for (int i = 0; i < pivottypes_len; i++) {
                double avg_sum = 0;
                for (int j = 0; j < CYCLES; j++)
                {
                        begin = clock();
                        iterative_quicksort(pivottypes[i], arr, 0, *collection_size);
                        end = clock();
                        double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
                        avg_sum += time_spent;
                        
                        for (int j = 0; j < *collection_size; j++) arr[j] = reference_arr[j];
                }
                
                switch (pivottypes[i]) {
                        case MEDIAN:
                                average_median_three = avg_sum / CYCLES;
                                break;
                        case FIRST:
                                average_first = avg_sum / CYCLES;
                                break;
                        case RANDOM:
                                average_random = avg_sum / CYCLES;
                                break;
                }
        }
        printresult(*collection_size, average_first, average_median_three, average_random, type);
}

void printresult(int collection_size, double average_first, double average_median_three, double average_random, int type)
{       
        printf("\n\n---- Results for %s quick sort algorithm (Median of three element pivot, Random element pivot, First element pivot) ----\n\n", type == RECURSIVE ? "RECURSIVE" : "ITERATIVE");
        printf("\n\nPivot element: Median of three\nExecution time for collection of size %d: %.16fms\n", collection_size, average_median_three);
        printf("\n\nPivot element: Random\nExecution time for collection of size %d: %.16fms\n", collection_size, average_random);
        printf("\n\nPivot element: First\nExecution time for collection of size %d: %.16fms\n", collection_size, average_first);
}