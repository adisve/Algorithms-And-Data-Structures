#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

#define CYCLES 10
#define RECURSIVE 0
#define ITERATIVE 1

/* Swap two elements passed by reference */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* ---------------------------------------------------------
 * Place the pivot element at the correct position in arr,
 * placing all elements in the partition that are less than 
 * the pivot on the left, greater than pivot on the right
 * --------------------------------------------------------- */
int partition(int *arr, int L, int H) 
{
	/* Set pivot to be arr[H] element in array */
	int pivot = arr[H];
	int pointer = (L - 1);

	/* Compare each element of partition to the pivot element */
	for (int i = L; i < H; i++) {
		if (arr[i] <= pivot) {
			/* Move pointer right in array */
			pointer++;
			swap(&arr[pointer], &arr[i]);
		}
	}
	/* Swap pivot with correct placement in partition */
	swap(&arr[pointer + 1], &arr[H]);
	return (pointer + 1);
}

/* ---------------------------------------------------------
 * Quick sort switching over recursive and iterative version,
 * depending on [type] variable. Iterative is faster simulates
 * the recursion call stack.
 * --------------------------------------------------------- */
void quicksort(int *arr, int L, int H, int type) 
{
	int top;
	int stack[H - L + 1];
	switch (type)
	{
		case RECURSIVE:
			if (L < H) {
				int pivot = partition(arr, L, H);
				/* Check left of current pivot */
				quicksort(arr, L, pivot-1, RECURSIVE);
				/* Check right of current pivot */
				quicksort(arr, pivot+1, H, RECURSIVE);
			}
			break;
		case ITERATIVE:
			top = -1;
			stack[++top] = L;
			stack[++top] = H;
		
			while (top >= 0) {
				H = stack[top--];
				L = stack[top--];
				int p = partition(arr, L, H);
		
				if (p - 1 > L) {
					stack[++top] = L;
					stack[++top] = p - 1;
				}
				if (p + 1 < H) {
					stack[++top] = p + 1;
					stack[++top] = H;
				}
			}
			break;
	}
	
}