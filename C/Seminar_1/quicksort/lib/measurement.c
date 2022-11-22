#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quicksort.h"
#include "measurement.h"

#define CYCLES          10
#define MEDIAN          0
#define FIRST           1
#define RANDOM          2
#define RECURSIVE       0
#define ITERATIVE       1
#define PIVOTS          3

static int PIVOT_TYPES[3] = {FIRST, RANDOM, MEDIAN};

void measure_r_qsort(int *arr, int* COLLECTION_SIZE, int type)
{
        
	clock_t end;
        clock_t begin;
        double avg_first;
        double avg_random;
        double avg_median;
        
        int *reference_arr = malloc(sizeof(int) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(int));

        for (int i = 0; i < PIVOTS; i++) {
                double avg_sum = 0;
                /* Execute quicksort for 10 cycles */
                for (int j = 0; j < CYCLES; j++)
                {
                        begin = clock();
                        r_qsort(PIVOT_TYPES[i], arr, 0, *COLLECTION_SIZE - 1);
                        end = clock();
                        double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
                        avg_sum += time_spent;

                        /* Reset sorted list to be old version */
                        memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(int));
                }
                
                switch (PIVOT_TYPES[i]) {
                        case MEDIAN:
                                avg_median = avg_sum / CYCLES;
                                break;
                        case FIRST:
                                avg_first = avg_sum / CYCLES;
                                break;
                        case RANDOM:
                                avg_random = avg_sum / CYCLES;
                                break;
                }
        }

        printresult(*COLLECTION_SIZE, avg_first, avg_median, avg_random, type);
}

void measure_i_qsort(int *arr, int* COLLECTION_SIZE, int type)
{
        clock_t end;
        clock_t begin;
        double avg_first;
        double avg_random;
        double avg_median;

        /* Copy array to keep unsorted version */
        int *reference_arr = malloc(sizeof(int) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(int));

        for (int i = 0; i < PIVOTS; i++) {
                double avg_sum = 0;
                for (int j = 0; j < CYCLES; j++)
                {
                        begin = clock();
                        i_qsort(PIVOT_TYPES[i], arr, 0, *COLLECTION_SIZE - 1);
                        end = clock();
                        double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
                        avg_sum += time_spent;
                        
                        /* Reset sorted list to be old version */
                        memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(int));
                }
                
                switch (PIVOT_TYPES[i]) {
                        case MEDIAN:
                                avg_median = avg_sum / CYCLES;
                                break;
                        case FIRST:
                                avg_first = avg_sum / CYCLES;
                                break;
                        case RANDOM:
                                avg_random = avg_sum / CYCLES;
                                break;
                }
        }
        printresult(*COLLECTION_SIZE, avg_first, avg_median, avg_random, type);
}

void printresult(int COLLECTION_SIZE, double avg_first, double avg_median, double avg_random, int type)
{       
        printf("\n\n---- Results for %s quick sort algorithm (Median of three element pivot, Random element pivot, First element pivot) ----\n\n", type == RECURSIVE ? "RECURSIVE" : "ITERATIVE");
        printf("\n\nPivot element: Median of three\nExecution time for collection of size %d: %.16f(ms)\n", COLLECTION_SIZE, avg_median);
        printf("\n\nPivot element: Random\nExecution time for collection of size %d: %.16f(ms)\n", COLLECTION_SIZE, avg_random);
        printf("\n\nPivot element: First\nExecution time for collection of size %d: %.16f(ms)\n", COLLECTION_SIZE, avg_first);
}