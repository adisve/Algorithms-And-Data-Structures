#ifndef PROBING_HASH_HEADER
#define PROBING_HASH_HEADER

typedef struct _hashtable_probing hashtable_probing;

typedef struct _hashentry hashentry;


struct _hashtable_probing
{
	hashentry *elements;
	int size;
	int capacity;
};

struct _hashentry
{
	int key;
	int value;
};


hashtable_probing * create_probing(void);
void destroy_probing(hashtable_probing *table);

int get_probing(hashtable_probing *table, int key);
int set_probing(hashtable_probing *table, const int key, const int value, const int type);

int linear_entry(hashentry *elements, const int capacity, const int key, const int value, int *table_len);
int quadratic_entry(hashentry *elements, const int capacity, const int key, const int value, int *table_len);
int enlarge(hashtable_probing *table, int type);

#endif