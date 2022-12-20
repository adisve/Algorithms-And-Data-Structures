#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/heap.h"

/**
 * @brief: Construct empty minheap
 * 
 * @retval minheap
 */
heap create()
{
	heap heap = malloc(sizeof(struct _heap));
	if (heap == NULL) abort();

	heap->max_size = 64;
	heap->size = 0;
	heap->arr = (key_type*) malloc(sizeof(key_type)*(heap->max_size+1));
	
	if (heap->arr == NULL) abort();
	
	return heap;
}

/**
 * @brief: Construct the binary heap given an array of items.
 * 
 * @param arr
 * @param n
 * @return minheap
 */
heap heapify(heap h, const key_type *arr, int n)
{
	/* Out of memory */
	if (h->arr == NULL)
		abort();
	h->size = n;

	for(int k = 0; k < n; k++)
		h->arr[k + 1] = arr[k];

	for(int k = (h->max_size)/2; k > 0; k--)
		percolatedown(h, k);
	return h;
}

heap buildheap(const key_type *arr, int n)
{
	assert(arr && n > 0);
	heap h = (heap) malloc(sizeof(struct _heap));

	if (h == NULL)
		abort();
	h->max_size = n;
	h->size = 0;
	h->arr = (key_type*) malloc(sizeof(key_type)*(h->max_size+1));
	return heapify(h, arr, n);
}
/**
 * @brief: Doubles size of minheap
 * 
 * @param heap
 */
void enlarge(heap heap)
{
	int new_max = 2 * heap->max_size;
	key_type* new_arr = (key_type*) malloc(sizeof(key_type) * (new_max + 1));
	if (new_arr == NULL) abort();

	for (int i = 1; i <= heap->size; i++)
		new_arr[i] = heap->arr[i];
	free(heap->arr);
	heap->arr = new_arr;
	heap->max_size = new_max;	
}

/**
 * @brief Compares the new element with its parent
 * and moving the new element up a level. Repeated until
 * the parent is less than or equal to the percolating element. 
 * 
 * @param heap 
 * @param k 
 */
void percolateup(heap heap, int k)
{
	assert(heap && k >= 1 && k <= heap->size);

	/* for(heap->arr[0] = k; k < heap->arr[k / 2]; k /= 2)
		swap(heap, k/2, k);
	heap->arr[k] = k; */
	
	/* Can also be written like this for clarity */
	while (k > 1 && heap->arr[k] < heap->arr[k / 2])
	{
		swap(heap, k / 2, k);
		k /= 2;
	} 
}

/**
 * @brief: Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time, O(N).
 * Interchange the node with the larger of its two children. 
 * Continue until it becomes a leaf node or until the heap property 
 * is restored.
 * 
 * @param  heap
 * @param  k: hole
 * @retval None
 */
void percolatedown(heap h, int k)
{
	assert(h);
	int j;
	key_type tmp = h->arr[k];
	for (j = k * 2; k * 2 <= h->size; k = j)
	{
		j = k * 2;
		if (j != h->size && h->arr[j + 1] < h->arr[j])
			j++;
		if (h->arr[j] < tmp)
			swap(h, k, j);
		else
			break;
	}
	h->arr[k] = tmp;

	// Should be written with more brevity like so:
	/* while (2 * k <= heap->size)
	{
		j = 2 * k;
		if (j < heap->size && heap->arr[j+1] < heap->arr[j]) j++;
		if (heap->arr[k] <= heap->arr[j]) break;

		swap(heap, k, j);
		k = j;
	} */
}

/**
 * @brief: Swap positions of two elements in heap
 * 
 * @param  heap
 * @param  i
 * @param  j
 * @retval None
 */
void swap(heap heap, int i, int j)
{
	assert(heap && i >= 1 && i <= heap->size && j >= 1 && j <= heap->size);
	key_type tmp = heap->arr[i];
	heap->arr[i] = heap->arr[j];
	heap->arr[j] = tmp;
}

/**
 * @brief: Insert into the priority queue, maintaining heap order.
 * Duplicates are allowed.
 *
 * @param  heap
 * @param  key: array item type (int, char, etc..)
 * @retval None
 */
void insert(heap heap, key_type key)
{
	assert(heap);
	if (heap->size == heap->max_size)
		enlarge(heap);
	heap->arr[++heap->size] = key;
	// Percolate up
	percolateup(heap, heap->size);
}

/**
 * @brief: Traverse tree in level order
 * 
 * @param heap 
 */
void levelorder(heap heap)
{
	for (int i = 1; i < heap->size+1; i++)
                printf("%d ", heap->arr[i]);
}

/**
 * @brief: Traverse tree in pre-order
 * @note   
 * @param  heap: 
 * @param  i: 
 * @retval None
 */
void preorder(heap heap, int i)
{
	if (i > 0 && i < heap->size)
	{
		/* Parent node */
		printf("%d ", heap->arr[i]);

		/* Left nodes */
		preorder(heap, 2 * i);

		/* Right nodes */
		preorder(heap, 2 * i + 1);
	}
}
/**
 * @brief: Traverse tree in post-order
 * @note   
 * @param  heap: 
 * @param  i: 
 * @retval None
 */
void postorder(heap heap, int i)
{
	if (i > 0 && i < heap->size)
	{
		/* Left nodes */
		postorder(heap, 2 * i);

		/* Right nodes */
		postorder(heap, 2 * i + 1);

		/* Parent node */
		printf("%d ", heap->arr[i]);
	}
}

/**
 * @brief: Traverse tree in order
 * @note   
 * @param  heap: 
 * @param  i: 
 * @retval None
 */
void inorder(heap heap, int i)
{
	if (i > 0 && i < heap->size)
	{
		/* Left nodes */
		inorder(heap, 2 * i);

		/* Parent node */
		printf("%d ", heap->arr[i]);

		/* Right nodes */
		inorder(heap, 2 * i + 1);
	}
}

/**
 * @brief: Return root of minheap
 * 
 * @param heap 
 * @return int 
 */
int findmin(heap heap)
{
	if (isempty(heap)) abort();
	return heap->arr[1];
}

void destroy(heap heap)
{
	assert(heap);
	free(heap->arr);
	free(heap);
}

/**
 * @brief: Delete root of minheap
 * @note   
 * @param  heap
 * @retval None
 */
void deletemin(heap heap)
{
	if (isempty(heap)) abort();
	swap(heap, 1, heap->size);
	heap->size--;
	percolatedown(heap, 1);
}

/**
 * @brief: Gives the size of the given minheap
 * 
 * @param heap 
 * @return int 
 */
int size(heap heap)
{
	assert(heap);
	return heap->size;
}

/**
 * @brief: Determines if minheap contains
 * any elements
 * 
 * @param heap 
 * @return int 
 */
int isempty(heap heap)
{
	assert(heap);
	return heap->size <= 0;
}

/**
 * @brief: Sets minheap size to 0
 * 
 * @param heap 
 */
void clear(heap heap)
{
	assert(heap);
	heap->size = 0;
}