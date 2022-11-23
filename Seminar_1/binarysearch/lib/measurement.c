#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "measurement.h"
#include "binarysearch.h"

#define CYCLE   10
#define MAX     100

/* ---------------------------------------------------------
 * Measure average runtime of binary search algorithm on
 * sorted input array of max size 1000000. Measured for 10
 * cycles.
 * --------------------------------------------------------- */
void measure_binarysearch(long *arr, long *COLLECTION_SIZE)
{
        time_t begin;
        time_t end;
        int found;
        double time_spent;
        double avg_sum = 0;
        double avg;
        for (int i = 0; i < CYCLE; i++)
        {

                /* Generate number to search for in range */
                long num = (rand() % (MAX - 0 + 1)) + 0;
                printf("\nNumber to search for: %ld\n", num);

                begin = clock();
                found = binarysearch(arr, 0, *COLLECTION_SIZE - 1, num);
                end = clock();
                found == -1 ? printf("\n\nElement %ld was not found\n", num) : printf("\n\nFound %ld at index %d", num, found);
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
        }
        avg = avg_sum / CYCLE;
        printf("\n---- RESULTS FOR BINARY SEARCH ----");
        printf("\nAverage time (10 cycles): %.16fms\n\n", avg*1000);
}