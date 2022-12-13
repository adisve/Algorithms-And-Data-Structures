#ifndef HEAP_HEADER
#define HEAP_HEADER

typedef int key_type;
typedef struct minheap* minheap;

minheap create();
minheap buildheap(const key_type* array, int n);

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

#endif