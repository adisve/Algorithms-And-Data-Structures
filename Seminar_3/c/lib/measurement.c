#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "heap.h"
#include "measurement.h"

#define CYCLES 10

void measure_algorithm_one(int *arr, int *COLLECTION_SIZE)
{
        clock_t end;
        clock_t begin;
	double time_spent;
        double avg_sum = 0;
        double avg;

        long *reference_arr = malloc(sizeof(int) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(int));

        for (int i = 0; i < CYCLES; i++) 
        {
                begin = clock();
                /* Create and fill heap */
                minheap heap_one = create();
                for (int i = 0; i < 15; i++)
                        insert(heap_one, arr[i]);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
                memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(long));
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

        long *reference_arr = malloc(sizeof(int) * *COLLECTION_SIZE);
        memcpy(reference_arr, arr, *COLLECTION_SIZE*sizeof(int));

        for (int i = 0; i < CYCLES; i++) 
        {
                begin = clock();
                /* Create heap from [arr] */
                heapify(arr, *COLLECTION_SIZE);
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                avg_sum += time_spent;
                memcpy(arr, reference_arr, *COLLECTION_SIZE*sizeof(long));
        }
        avg = avg_sum / CYCLES;
        free(reference_arr);
        printf("\nExecution time for collection of size %d: %.16fms\n", *COLLECTION_SIZE, avg*1000);
}