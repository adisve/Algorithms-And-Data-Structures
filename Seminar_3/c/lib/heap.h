#ifndef HEAP_HEADER
#define HEAP_HEADER

void heapify(int *arr, int *size, int i);
void insert(int *arr, int i, int *size);
void removeroot(int *arr, int i, int *size);
void swap(int *x, int *y);
#endif