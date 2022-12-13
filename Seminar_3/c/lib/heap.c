#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

struct minheap {
	key_type* array;
	int max_size;
	int size;
};

/**
 * @brief: Construct the binary heap given an array of items.
 * @param  array: array of items
 * @retval minheap
 */
minheap buildheap(const key_type* array)
{
	/* Allocate memory in heap for minheap. Not necessary in Java */
	minheap heap = (minheap) malloc(sizeof(struct minheap));
	if (heap == NULL) abort();

	heap->max_size = 64;
	heap->size = 0;
	heap->array = (key_type*) malloc(sizeof(key_type)*(heap->max_size+1));
	if (heap->array == NULL) abort();

	return heap;
}

void destroy(minheap heap)
{
	assert(heap);
	free(heap->array);
	free(heap);
}


static void percolateup(minheap heap, int k) 
{
	assert(heap && k >= 1 && k <= heap->size);

	for(heap->array[0] = k; k < heap->array[k / 2]; k /= 2)
		swap(heap, k/2, k);
	heap->array[k] = k;
	
	/* Can also be written like this */
	/* while (k > 1 && heap->array[k] < heap->array[k / 2])
	{
		swap(heap, k / 2, k);
		k /= 2;
	} */
}

/**
 * @brief: Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time, O(N)
 * @param  heap: struct minheap
 * @param  k: newly added element
 * @retval None
 */
static void percolatedown(minheap heap, int k)
{
	assert(heap);
	int child;
	key_type tmp = heap->array[k];
	for (; k * 2 <= heap->size; k = child)
	{
		child = k * 2;
		if (child != heap->size && heap->array[child + 1] < heap->array[child])
			child++;
		if (heap->array[child] < tmp)
			heap->array[k] = heap->array[child];
		else
			break;
	}
	heap->array[k] = tmp;

	// Should be written with more brevity like so:
	/* while (2 * k <= heap->size)
	{
		int j = 2 * k;
		if (j < heap->size && heap->array[j+1] < heap->array[j]) j++;
		if (heap->array[k] <= heap->array[j]) break;

		swap(heap, k, j);
		k = j;
	} */
}

/**
 * @brief: Swap positions of two elements in heap
 * @param  heap: struct minheap
 * @param  i: element i
 * @param  j: element j
 * @retval None
 */
void swap(minheap heap, int i, int j)
{
	assert(heap && i >= 1 && i <= heap->size && j >= 1 && j <= heap->size);
	key_type tmp = heap->array[i];
	heap->array[i] = heap->array[j];
	heap->array[j] = tmp;
}

/**
 * @brief: Insert into the priority queue, maintaining heap order.
 * Duplicates are allowed.
 * @note   
 * @param  heap: struct minheap
 * @param  key: array type (int, char, etc..)
 * @retval None
 */
void insert(minheap heap, key_type key)
{
	assert(heap);
	if (heap->size == heap->max_size)
		enlarge(heap);
	heap->array[++heap->size] = key;
	// Percolate up
	percolateup(heap, heap->size);
}

int findmin(minheap heap)
{
	if (isempty(heap)) abort();
	return heap->array[1];
}

/**
 * @brief:   
 * @note   
 * @param  heap: 
 * @retval None
 */
void deletemin(minheap heap)
{
	if (isempty(heap)) abort();
	swap(heap, 1, heap->size);
	heap->size--;
	percolatedown(heap, 1);
}

int size(minheap heap)
{
	assert(heap);
	return heap->size;
}

int isempty(minheap heap)
{
	assert(heap);
	return heap->size <= 0;
}

void clear(minheap heap)
{
	assert(heap);
	heap->size = 0;
}

minheap heapify(const key_type* array, int n)
{
	assert(array && n > 0);

	minheap heap = (minheap) malloc(sizeof(struct minheap));
	if (heap == NULL) abort();

	heap->max_size = n;
	heap->size = 0;
	heap->array = (key_type*) malloc(sizeof(key_type) * (heap->max_size + 1));

	if (heap->array == NULL) abort();

	heap->size = n;
	for (int k = 0; k < n; k++)
		heap->array[k+1] = array[k];
	for (int k = (heap->max_size+1) / 2; k > 0; k--)
		percolatedown(heap, k);
	return heap;		
}

void enlarge(minheap heap)
{
	int new_max = 2 * heap->max_size;
	key_type* new_arr = (key_type*) malloc(sizeof(key_type) * (new_max + 1));
	if (new_arr == NULL) abort();

	for (int i = 1; i <= heap->size; i++)
		new_arr[i] = heap->array[i];
	free(heap->array);
	heap->array = new_arr;
	heap->max_size = new_max;	
}