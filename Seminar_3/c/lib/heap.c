#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(int *x, int *y)
{
	int temp = *y;
	*y = *x;
	*x = temp;
}

void heapify(int *arr, int *size, int i)
{
	if (*size == 1) printf("Only one element in heap");
	else
	{
		int parent = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < *size && arr[left] > arr[parent]) parent = left;
		if (right < *size && arr[right] > arr[parent]) parent = right;
		if (parent != i)
		{
			swap(&arr[i], &arr[parent]);
			heapify(arr, size, parent);
		}
	}
}

void insert(int *arr, int i, int *size)
{
  	if (*size == 0)
	{
		arr[*size] = i;
		*size += 1;
	}
  	else
  	{
    		arr[*size] = i;
		*size += 1;
    		for (int j = *size / 2 - 1; j >= 0; j--)
      			heapify(arr, size, j);
  	}
}

void removeroot(int *arr, int num, int *size)
{
  	int j;
	for (j = 0; j < *size; j++)
		if (num == arr[j])
			break;

  	swap(&arr[j], &arr[*size - 1]);
	*size -= 1;
  	for (int j = *size / 2 - 1; j >= 0; j--)
    		heapify(arr, size, j);
}