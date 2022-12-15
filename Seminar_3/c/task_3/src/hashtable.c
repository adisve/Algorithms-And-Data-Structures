#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/hashtable.h"

// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
static uint64_t hashcode(const char* key) {
    uint64_t hashcode = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hashcode ^= (uint64_t)(unsigned char)(*p);
        hashcode *= FNV_PRIME;
    }
    return hashcode;
}


hashtable * create()
{
        hashtable *table = (hashtable*) (malloc(sizeof(struct _hashtable)));
        if (table == NULL)
        {
                fprintf(stderr, "Could not create hash table");
                return NULL;
        }
        table->size = 0;
        table->capacity = CAPACITY;

        table->elements = (hashentry*) calloc(table->capacity, sizeof(struct _hashentry));

        if (table->elements == NULL)
        {
                free(table);
                fprintf(stderr, "Could not create hash table elements");
        }
        return table;
}

void destroy(hashtable *table)
{
        free(table->elements);
        free(table);
}


const char * set(hashtable *table, const char *key, char *value)
{
        if (value == NULL) return NULL;
        /* Ensure load capacity is not exceeded (0.5) */
        if (table->size >= table->capacity / 2)
                if (!enlarge(table))
                        return NULL;
        return set_entry(table->elements, table->capacity, key, value, &table->size);
}

char * get(hashtable *table, const char *key)
{
        uint64_t hash = hashcode(key);
        /* Using AND operation to make sure index is not out of
         * bounds (works if table size is a power of 2) */
        size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

        while (table->elements[index].key != NULL) {
                if (strcmp(key, table->elements[index].key) == 0)
                        return table->elements[index].value;
                index++;
                if (index >= table->capacity)
                        index = 0;
        }
        return NULL;
}

const char * set_entry(hashentry *elements, const int capacity, const char *key, char *value, int *table_len)
{
        printf("\nTrying to insert %s into table : ", value);
        uint64_t hash = hashcode(key);
        int index = hash % capacity;
        while (elements[index].key != NULL)
        {
                if (strcmp(elements[index].value, value) == 0)
                {
                        printf("Error -> %s already exists in table -> Compared old value:(%s) and new value: (%s)", value, elements[index].value, value);
                        return NULL;
                }
                index = (index + 1) % capacity;
        }
        if (table_len != NULL)
        {
                key = strdup(key);
                if (key == NULL)
                        return NULL;
                (*table_len)++;
        }
        elements[index].key = (char*)key;
        printf("Success -> inserted %s", value);
        elements[index].value = value;
        return key;
}

int contains(hashtable *table, const char *key)
{
        uint64_t hash = hashcode(key);
        size_t index = hash % table->capacity;
        return table->elements[index].key != NULL;
}

int enlarge(hashtable *table)
{
        size_t new_capacity = table->capacity * 2;
        if (new_capacity < table->capacity) {
                return -1;
        }
        hashentry *new_entries = (hashentry*) calloc(new_capacity, sizeof(struct _hashentry));
        if (new_entries == NULL) {
                return -1;
        }

        for (size_t i = 0; i < table->capacity; i++) {
                hashentry entry = table->elements[i];
                if (entry.key != NULL)
                        set_entry(new_entries, new_capacity, entry.key, entry.value, NULL);
        }

        free(table->elements);
        table->elements = new_entries;
        table->capacity = new_capacity;
        return 0;
}