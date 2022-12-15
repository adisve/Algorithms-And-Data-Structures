#ifndef PROBING_HASH_HEADER
#define PROBING_HASH_HEADER

typedef struct _probing_hashtable probing_hashtable;

typedef struct _hashentry hashentry;


struct _probing_hashtable
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


probing_hashtable * create_probing(void);
void destroy_probing(probing_hashtable *table);

int get_probing(probing_hashtable *table, int key);
int set_probing(probing_hashtable *table, const int key, const int value, const int type);

int linear_entry(hashentry *elements, const int capacity, const int key, const int value, int *table_len);
int quadratic_entry(hashentry *elements, const int capacity, const int key, const int value, int *table_len);
int enlarge(probing_hashtable *table, int type);

#endif