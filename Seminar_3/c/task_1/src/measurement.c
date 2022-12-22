#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../lib/heap.h"
#include "../lib/measurement.h"

#define CYCLES 10

void measure_algorithm_one(int *arr, int *COLLECTION_SIZE)
{
        clock_t end;
        clock_t begin;
	double time_spent;
        double avg_sum = 0;
        double avg;

        int *reference_arr = malloc(sizeof(int) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(int));

        for (int i = 0; i < CYCLES; i++) 
        {
                begin = clock();
                /* Create and fill heap */
                heap heap_one = create();
                for (int j = 0; j < 15; j++)
                        insert(heap_one, arr[j]);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
                memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(int));
        }
        avg = avg_sum / CYCLES;
        free(reference_arr);
        
        printf("\nExecution time for collection of size %d: %.16fms\n", *COLLECTION_SIZE, avg*1000);
}

void measure_algorithm_two(int *arr, int *COLLECTION_SIZE)
{
        clock_t end;
        clock_t begin;
	double time_spent;
        double avg_sum = 0;
        double avg;

        int *reference_arr = malloc(sizeof(int) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(int));

        for (int i = 0; i < CYCLES; i++) 
        {
                begin = clock();
                /* Create heap from [arr] */
                buildheap(arr, *COLLECTION_SIZE);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
                memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(int));
        }
        avg = avg_sum / CYCLES;
        free(reference_arr);
        printf("\nExecution time for collection of size %d: %.16fms\n", *COLLECTION_SIZE, avg*1000);
}