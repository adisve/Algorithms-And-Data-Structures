#include <stdio.h>
#include <stdlib.h>
#include "../lib/chaining_hash.h"

#define CAPACITY 8
#define hashcode_first(x) x % 10
#define hashcode_second(x) 7 - x //h2(x) = 7 − (x mod 7)

hashtable_chain * create_chain(void)
{
        hashtable_chain *table = (hashtable_chain*) (malloc(sizeof(struct _hashtable_chain)));
        if (table == NULL)
        {
                fprintf(stderr, "Could not create hash table");
                return NULL;
        }
        table->capacity = CAPACITY;
        table->elements = calloc(table->capacity, sizeof(struct _node));

        if (table->elements == NULL)
        {
                free(table);
                fprintf(stderr, "Could not create hash table");
        }
        return table;
        
}

node* get_chain(hashtable_chain *table, int key)
{
        int i = 1;
        int index = (hashcode_second(hashcode_first(key) + i)) % table->capacity;
        node *p;

        for(p = table->elements[index]; p != NULL; p = p->next)
        {
            if(p->value == key)
                {
                    return p;
                }
        }
        return NULL;  
}

node* set_chain(hashtable_chain *table, const int key, const int value)
{
        node *n = (node*) malloc(sizeof(struct _node));
        node *p;
        n->value=value;
        n->next = NULL;

        int index = hashcode_second(hashcode_first(key)) % table->capacity;

        if(table->elements[index] == NULL)
        {
                table->elements[index] = n;
                return n;
        }
        else
        {
                p = table->elements[index];
                while(p->next != NULL)
                        p = p->next;
                p->next = n;
                return n;
        }
        printf("\nCould not insert %d\n", key);
        return NULL;
}


void destroy_chain(hashtable_chain *table)
{
        free(table->elements);
        free(table);
}