#include <stdio.h>
#include <stdlib.h>
#include "../lib/chaining_hash.h"
#include "../lib/test_chaining.h"

#define SIZE 7

void a(int *input)
{
        printf("\n\na) [Hash table with chaining] ");
        hashtable_chain *table = create_chain();

        for (int i = 0; i < SIZE; i++)
                set_chain(table, input[i], input[i]);

        for (int i = 0; i < table->capacity; i++)
        {
                printf("\nIndex %d: ", i);
                if (table->elements[i] != NULL)
                {
                        node *n = table->elements[i];
                        while (n != NULL)
                        {
                                printf("%d -> ", n->value);
                                n = n->next;
                        }
                        printf("NULL");
                }
        }
        destroy_chain(table);
}