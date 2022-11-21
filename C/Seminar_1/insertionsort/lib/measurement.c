#include <stdio.h>
#include <time.h>
#include "insertionsort.h"
#include "measurement.h"

#define CYCLES 10

void measure_insertionsort(int *arr, int *reference_arr, int size)
{

        clock_t end;
        clock_t begin;
	double time_spent;
        double avg_sum = 0;
        double avg;

        for (int i = 0; i < CYCLES; i++) 
        {
                begin = clock();
                insertionsort(arr, size);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
                printf("\nCompleted cycle number %d, which took %.16fms..", i+1, time_spent*1000);
                
                /* Reset sorted list to be old version */
                for (int j = 0; j < size; j++) arr[j] = reference_arr[j];
        }
        avg = avg_sum / CYCLES;
        printf("\n\n---- Results for insertion sort algorithm ----\n\n");
        printf("\n\nExecution time for collection of size %d: %.16fms\n\n", size, avg*1000);
}