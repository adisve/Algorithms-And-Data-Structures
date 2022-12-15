#ifndef HASHTABLE_HEADER
#define HASHTABLE_HEADER

#define CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

typedef struct _hashtable hashtable;
typedef struct _hashentry hashentry;

struct _hashtable
{
	hashentry *elements;
	int capacity;
        int size;
};

struct _hashentry
{
	const char *key;
	char* value;
};

hashtable * create();
void destroy(hashtable *table);

char * get(hashtable *table, const char *key);
const char * set(hashtable *table, const char *key, char *value);
const char * set_entry(hashentry *elements, const int capacity, const char *key, char *value, int *table_len);
int contains(hashtable *table, const char *word);
int enlarge(hashtable *table);


#endif