#ifndef CHAINING_HASH_HEADER
#define CHAINING_HASH_HEADER

typedef struct _chained_hashtable chained_hashtable;
typedef struct _node node;

struct _chained_hashtable
{
	node* *elements;
	int capacity;
};

struct _node
{
	int value;
	node *next;
};

chained_hashtable * create_chain(void);
void destroy_chain(chained_hashtable *table);

node * get_chain(chained_hashtable *table, int key);
node * set_chain(chained_hashtable *table, const int key, const int value);

#endif