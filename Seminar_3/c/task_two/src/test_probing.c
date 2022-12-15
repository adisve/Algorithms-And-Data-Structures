#include <stdio.h>
#include <stdlib.h>
#include "../lib/probing_hash.h"
#include "../lib/test_probing.h"

#define SIZE 7
#define LINEAR 0
#define QUADRATIC 1

void b(int *input)
{
        printf("\n\nb) [Hash table with linear probing] ");
        hashtable_probing *table = create_probing();
        for (int i = 0; i < SIZE; i++)
                set_probing(table, input[i], input[i], LINEAR);
        for (int i = 0; i < table->capacity; i++)
                printf("%d ", table->elements[i].value);        
        destroy_probing(table);
}

void c(int *input)
{
        printf("\n\nc) [Hash table with quadratic probing] ");
        hashtable_probing *table = create_probing();
        for (int i = 0; i < SIZE; i++)
                set_probing(table, input[i], input[i], QUADRATIC);
        for (int i = 0; i < table->capacity; i++)
                printf("%d ", table->elements[i].value);        
        destroy_probing(table);
}