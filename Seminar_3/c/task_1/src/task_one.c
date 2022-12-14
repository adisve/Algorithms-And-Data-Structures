#include <stdio.h>
#include <stdlib.h>
#include "../lib/task_one.h"
#include "../lib/heap.h"
#include "../lib/measurement.h"

#define MAX 100000

void a(heap heap)
{
        printf("\n\n---- Task 1 ----\n\n");
        printf("a) ->  ");
        levelorder(heap);
        printf("\n");
}

void b(heap heap)
{
        printf("\nb) ->  ");
        levelorder(heap);
        printf("\n");
}

void c(heap heap_one, heap heap_two, int i)
{
        printf("\n");
        printf("c) \n");
        printf(" -> Pre-order traversal array 1:  ");
        preorder(heap_one, 1);
        printf("\n");
        printf(" -> Pre-order traversal array 2:  ");
        preorder(heap_two, 1);
        printf("\n\n");
        printf(" -> In-order traversal array 1: ");
        inorder(heap_one, 1);
        printf("\n");
        printf(" -> In-order traversal array 2: ");
        inorder(heap_two, 1);
        printf("\n\n");
        printf(" -> Post-order traversal array 1: ");
        postorder(heap_one, 1);
        printf("\n");
        printf(" -> Post-order traversal array 2: ");
        postorder(heap_two, 1);
        printf("\n\n");
        printf(" -> Level-order traversal array 1: ");
        levelorder(heap_one);
        printf("\n");
        printf(" -> Level-order traversal array 2: ");
        levelorder(heap_two);
        printf("\n");
}

void d()
{
        printf("\nd)\n");
        FILE *inputfile;
        int SUBSET_SIZE;
        int COLLECTION_SIZE = MAX;
        int *arr = malloc(sizeof(int) * COLLECTION_SIZE);
        inputfile = fopen("random_numbers.txt", "r");

        if(inputfile == NULL)
        {
                printf("Error reading file. Make sure 'random_numbers.txt' is available for benchmarking purposes ..\n");
                abort();
        }
        /* Read numbers from file into integer array */
        for (int i = 0; i < COLLECTION_SIZE; i++) fscanf(inputfile, "%d", &arr[i]);


        printf("\n\n---- Results for algorithm one ----\n\n");
        for (int i = MAX; i > 0; i /= 10)
        {
                printf("\nGoing in to allocate ..");
                int *subset = malloc((i)*sizeof(int));
                
                for(int j = i; j < i; j++)
                        subset[j] = arr[j];
                SUBSET_SIZE = i;
                measure_algorithm_one(subset, &SUBSET_SIZE);
                free(subset);
        }

        printf("\n\n---- Results for algorithm two ----\n\n");
        for (int i = MAX; i > 0; i /= 10)
        {
                int *subset = malloc((i)*sizeof(int));
                for(int j = i; j < i; j++)
                        subset[j] = arr[j];
                SUBSET_SIZE = i;
                measure_algorithm_two(subset, &SUBSET_SIZE);
                free(subset);
        }     
}