#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/puzzle.h"
#include "../lib/hashtable.h"

/**
 * @brief: Create hashtable of size 'capacity' 
 * and fill each index with a substring of
 * each word (0, len(word)) as links (nodes)
 * of prefixes
 * @note   
 * @param  **words: 
 * @param  capacity: 
 * @retval 
 */
hashtable * fill(char **words, int capacity)
{
        hashtable *table = create(capacity);
        for (int i = 0; i < capacity; i++)
        {
                char *current_word = words[i];
                printf("\nCurrent word: %s -> ", current_word);
                int length = strlen(current_word);
                /* For every letter in the word */
                for (int j = 0; j < length; j++)
                {
                        char *sub = (char*) malloc(sizeof(char)*j+1);
                        substr(current_word, sub, 0, j+1);
                        
                        printf("\t\nSubstring of %s from %d to %d -> %s", current_word, 0, j+1, sub);

                        set(table, sub, sub);
                        free(sub);
                }
                        
        }
        return table;     
}

void solve()
{
        char *words[4] = { "this", "two", "fat", "that" };
        hashtable *table = fill(words, 4);
        display(table);
        destroy(table);
}

void display(hashtable *table)
{
       for (int i = 0; i < table->capacity; i++)
                printf("%s, ", table->elements[i].value);
}

void substr(char* str, char* sub , int start, int len)
{
    memcpy(sub, &str[start], len);
    sub[len] = '\0';
}