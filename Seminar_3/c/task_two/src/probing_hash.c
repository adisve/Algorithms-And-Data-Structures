#include <stdio.h>
#include <stdlib.h>
#include "../lib/probing_hash.h"

#define CAPACITY 8;
#define hashcode_first(x) x % 10
#define hashcode_second(x) 7 - x //h2(x) = 7 − (x mod 7)
#define LINEAR 0
#define QUADRATIC 1

hashtable_probing* create_probing(void)
{
        hashtable_probing *table = (hashtable_probing*) (malloc(sizeof(struct _hashtable_probing)));
        if (table == NULL)
        {
                fprintf(stderr, "Could not create hash table");
                return NULL;
        }

        table->size = 0;
        table->capacity = CAPACITY;

        /* Fill with zeros */
        table->elements = calloc(table->capacity, sizeof(struct _hashentry));

        for (int i = 0; i < table->capacity; i++)
                table->elements[i].key = -1;
        

        if (table->elements == NULL)
        {
                free(table);
                fprintf(stderr, "Could not create hash table");
                return NULL;
        }
        return table;
}



void destroy_probing(hashtable_probing *table)
{
        free(table->elements);
        free(table);
}



int get_probing(hashtable_probing *table, int key)
{
        int i = 1;
        int index = (hashcode_second(hashcode_first(key) + i)) % table->capacity;
        while (table->elements[index].key != -1)
        {
                if (key == table->elements[index].key)
                        return table->elements[index].value;
                index = (hashcode_second(hashcode_first(key) + i)) % table->capacity;
                i+=1;
        }
        return -1;        
}

int set_probing(hashtable_probing *table, int key, int value, const int type)
{
        if (value == -1) return -1;
        if (table->size >= table->capacity / 2) {
                if (!enlarge(table, type)) {
                        return -1;
                }
        }
        switch (type)
        {
                case LINEAR:
                        return linear_entry(table->elements, table->capacity, key, value, &table->size);
                case QUADRATIC:
                        return quadratic_entry(table->elements, table->capacity, key, value, &table->size);
        }
        return -1;
}

int quadratic_entry(hashentry *elements, const int capacity, const int key, const int value, int *table_len)
{
        int i = 0;
        int index = (hashcode_second(hashcode_first(key) + (i * i))) % capacity;

        while (elements[index].key != -1)
        {
                if (key == elements[index].key)
                {
                        /* Update key value */
                        elements[index].value = value;
                        return elements[index].key;
                }
                index = (hashcode_second(hashcode_first(key) + (i * i))) % capacity;
                i+=1;
        }
        if (table_len != NULL)
                (*table_len+=1);
        elements[index].key = key;
        elements[index].value = value;
        return key;
}

int linear_entry(hashentry *elements, const int capacity, const int key, const int value, int *table_len)
{
        int i = 0;
        int index = (hashcode_second(hashcode_first(key) + i)) % capacity;

        while (elements[index].key != -1)
        {
                if (key == elements[index].key)
                {
                        /* Update key value */
                        elements[index].value = value;
                        return elements[index].key;
                }
                index = (hashcode_second(hashcode_first(key) + i)) % capacity;
                i+=1;
        }
        if (table_len != NULL)
                (*table_len+=1);
        elements[index].key = key;
        elements[index].value = value;
        return key;
}

int enlarge(hashtable_probing *table, int type)
{
        int new = table->capacity * 2;
        /* Integer overflow */
        if (new < table->capacity) return 0;

        hashentry *tmp_elements = calloc(new, sizeof(struct _hashentry));
        if (tmp_elements == NULL) return 0;

        /* Set all new keys to -1 for availability */
        for (int i = 0; i < new; i++)
                tmp_elements[i].key = -1;

        /* Fill table with old values */
        for (int i = 0; i < table->capacity; i++)
        {
                hashentry element = table->elements[i];
                if (element.key != -1)
                {
                        switch (type)
                        {
                        case LINEAR:
                                linear_entry(tmp_elements, new, element.key, element.value, NULL);
                                break;
                        
                        case QUADRATIC:
                                quadratic_entry(tmp_elements, new, element.key, element.value, NULL);
                                break;
                        }
                }
        }
        free(table->elements);
        table->elements = tmp_elements;
        table->capacity = new;
        return 1;
}