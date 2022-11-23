#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "insertionsort.h"
#include "measurement.h"

#define CYCLES 10

void measure_insertionsort(long *arr, long *COLLECTION_SIZE)
{

        clock_t end;
        clock_t begin;
	double time_spent;
        double avg_sum = 0;
        double avg;

        long *reference_arr = malloc(sizeof(long) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(long));

        for (int i = 0; i < CYCLES; i++) 
        {
                begin = clock();
                insertionsort(arr, *COLLECTION_SIZE);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
                
                printf("\nCompleted cycle number %d, which took %.16fms..", i+1, time_spent*1000);
                
                memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(long));
        }
        avg = avg_sum / CYCLES;
        free(reference_arr);
        printf("\n\n---- Results for insertion sort algorithm ----\n\n");
        printf("\n\nExecution time for collection of size %ld: %.16fms\n\n", *COLLECTION_SIZE, avg*1000);
}