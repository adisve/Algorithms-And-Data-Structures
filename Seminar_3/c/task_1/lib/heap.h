#ifndef HEAP_HEADER
#define HEAP_HEADER

typedef int key_type;
typedef struct _heap* heap;

struct _heap
{
	key_type *arr;
	int max_size;
	int size;
};

heap create();
heap heapify(heap h, const key_type *arr, int n);
heap buildheap(const key_type *arr, int n);

void destroy(heap);
int findmin(heap);
void insert(heap, key_type);
void deletemin(heap);

int isempty(heap);
int size(heap);
void clear(heap);
void swap(heap heap, int i, int j);

void enlarge(heap heap);
void percolatedown(heap heap, int k);
void percolateup(heap heap, int k);

void preorder(heap heap, int i);
void postorder(heap heap, int i);
void inorder(heap heap, int i);
void levelorder(heap);

#endif