#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

#define CYCLES 10


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
 * the pivot on the left, greater than the pivot on the right
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
 * Recursive quick sort implementation
 * --------------------------------------------------------- */
void recursive_quicksort(int *arr, int L, int H) 
{
	if (L < H)
	{
		int pivot = partition(arr, L, H);
		/* Check left of current pivot */
		recursive_quicksort(arr, L, pivot-1);
		/* Check right of current pivot */
		recursive_quicksort(arr, pivot+1, H);
	}
}

/* ---------------------------------------------------------
 * Iterative quick sort implementation
 * --------------------------------------------------------- */
void iterative_quicksort(int *arr, int L, int H)
{
	int top = -1;
	int stack[H - L + 1];
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
}