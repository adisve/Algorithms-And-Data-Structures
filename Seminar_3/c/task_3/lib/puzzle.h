#ifndef PUZZLE_HEADER
#define PUZZLE_HEADER
#include "../lib/hashtable.h"

hashtable * fill(char **words, int capacity);
void display(hashtable *table);
void solve();
void substr(char* str, char* sub , int start, int len);

#endif