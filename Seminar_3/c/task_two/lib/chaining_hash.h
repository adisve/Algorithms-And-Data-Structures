#ifndef CHAINING_HASH_HEADER
#define CHAINING_HASH_HEADER

typedef struct _hashtable_chain hashtable_chain;
typedef struct _node node;

struct _hashtable_chain
{
	node* *elements;
	int capacity;
};

struct _node
{
	int value;
	node *next;
};

hashtable_chain * create_chain(void);
void destroy_chain(hashtable_chain *table);

node * get_chain(hashtable_chain *table, int key);
node * set_chain(hashtable_chain *table, const int key, const int value);

#endif