#ifndef HEAP_HEADER
#define HEAP_HEADER

typedef int key_type;
typedef struct _minheap* minheap;

struct _minheap {
	key_type *arr;
	int max_size;
	int size;
};

minheap create();
minheap heapify(const key_type *arr, int n);

void destroy(minheap);
int findmin(minheap);
void insert(minheap, key_type);
void deletemin(minheap);

int isempty(minheap);
int size(minheap);
void clear(minheap);
void swap(minheap heap, int i, int j);

void enlarge(minheap heap);
void percolatedown(minheap heap, int k);
void percolateup(minheap heap, int k);

void preorder(minheap heap, int i);
void postorder(minheap heap, int i);
void inorder(minheap heap, int i);
void levelorder(minheap);

#endif