#include <stdio.h>
#include <time.h>
#include "measurement.h"
#include "binarysearch.h"

#define CYCLE   10

/* ---------------------------------------------------------
 * Measure average runtime of binary search algorithm on
 * sorted input array of max size 1000000. Measured for 10
 * cycles.
 * --------------------------------------------------------- */
void measure_binarysearch(int *arr, int size, int element)
{
        time_t begin;
        time_t end;
        int found;
        double time_spent;
        double avg_sum = 0;
        double avg;
        for (int i = 0; i < CYCLE; i++)
        {
                begin = clock();
                found = binarysearch(arr, 0, size - 1, element);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
        }
        avg = avg_sum / CYCLE;
        printf("\n---- RESULTS FOR BINARY SEARCH FOR ELEMENT %d ----", element);
        found == -1 ? printf("\n\nElement %d was not found", element) : printf("\n\nFound %d at index %d", element, found);
        printf("\nAverage time (10 cycles): %.16fms\n\n", avg*1000);
}