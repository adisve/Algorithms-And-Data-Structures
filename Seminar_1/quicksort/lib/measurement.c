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

void measure_quicksort(int *arr, int *reference_arr, int collection_size, int type)
{
	clock_t end;
        clock_t begin;
	/* Reset sorted list to be old version */
	for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];
	
        int pivot;
	double time_spent;
        double average_rec_first;
        double average_rec_random;
        int pivottypes[3] = {0, 1, 2};
        double average_rec_median_three;
        size_t pivottypes_len = sizeof(pivottypes)/sizeof(pivottypes[0]);

        for (int i = 0; i < pivottypes_len; i++) {
                double avg_sum = 0;
                /* Dynamically set pivot type */
                switch (pivottypes[i]) {
                        case MEDIAN:
                                pivot = medianthree(arr[0], arr[(collection_size-1)/2], arr[collection_size-1]);
                                break;
                        case FIRST:
                                pivot = arr[0];
                                break;
                        case RANDOM:
                                /* Random element pivot test of quick sort */
		                pivot = arr[rand() % (collection_size-1)];
                                break;
                }

                /* Execute quicksort for 10 cycles */
                for (int i = 0; i < CYCLES; i++)
                {
                        /* ---------------------------------------------------------
                         * Only measure time it takes for sorting algorithm to finish 
                         */
                        begin = clock();
                        quicksort(arr, 0, pivot, type);
                        end = clock();
                        /* --------------------------------------------------------- */

                        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                        avg_sum += time_spent;

                        /* Reset sorted list to be old version */
                        for (int j = 0; j < collection_size; j++) arr[j] = reference_arr[j];
                }
                switch (pivottypes[i]) {
                        case MEDIAN:
                                average_rec_median_three = avg_sum / CYCLES;
                                break;
                        case FIRST:
                                average_rec_first = avg_sum / CYCLES;
                                break;
                        case RANDOM:
                                average_rec_random = avg_sum / CYCLES;
                                break;
                }
        }

        printf("\n\n---- Results for %s quick sort algorithm (Median of three element pivot, Random element pivot, First element pivot) ----\n\n", type == 0 ? "RECURSIVE" : "ITERATIVE");
        printf("\n\nPivot element: Median of three\nExecution time for collection of size %d: %.16fms\n", collection_size, average_rec_median_three*1000);
        printf("\n\nPivot element: Random\nExecution time for collection of size %d: %.16fms\n", collection_size, average_rec_random*1000);
        printf("\n\nPivot element: First\nExecution time for collection of size %d: %.16fms\n", collection_size, average_rec_first*1000);
}