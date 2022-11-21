#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"
#include "quicksort.h"
#include "measurement.h"

#define CYCLES 20
#define MEDIAN  0
#define FIRST   1
#define RANDOM  2

/* Swap two elements passed by reference */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/* ---------------------------------------------------------
 * Selectes the first element in the partition to be the
 * designated pivot point
 * --------------------------------------------------------- */
int partition_first(int *arr, int L, int H) 
{
	int pivot = arr[L];
	int pointer = (L + 1);

	for (int j = L + 1; j <= H; j++) {
		if (arr[j] < pivot) {
			if (j != pointer) {
				swap(&arr[pointer], &arr[j]);
			}
			pointer++;
		}
	}

	swap(&arr[pointer - 1], &arr[L]);
	return (pointer - 1);
}

int partition_last(int *arr, int L, int H) {
	int pivot = arr[H];
	int i = (L - 1);

	for (int j = L; j < H; j++) {
		if (arr[j] < pivot) {
			swap(&arr[++i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[H]);
	return (i + 1);
}

int partition_median(int* arr, int L, int H) {
	/* Find index of middle element in sub section */
	int middle = (L + H) / 2;

	/* If the middle element is smaller than the one on
	 * the far left, swap their positions */
	if (arr[middle] < arr[L]) 
		swap(&arr[middle], &arr[L]);
	/* If the element on the far right is smaller than the
	 * element on the far left the far left, swap their positions */
	if (arr[H] < arr[L])
		swap(&arr[H], &arr[L]);
	/* If the element on the far right is smaller than the
	 * element in the middle, swap their places */
	if (arr[H] < arr[middle])
		swap(&arr[H], &arr[middle]);
	/* Swap places with the middle element and the element
	 * on the left of the far right element in the array */
	swap(&arr[middle], &arr[H-1]);
	return partition_first(arr, L, H);
}

int partition_random(int *arr, int L, int H)
{
	int random = (rand() % (H - L + 1)) + L;
	swap(&arr[random], &arr[H]);
	return partition_last(arr, L, H);
}

/* ---------------------------------------------------------
 * Recursive quick sort implementation
 * --------------------------------------------------------- */
void recursive_quicksort(int pivot_type, int *arr, int L, int H) 
{
	if (H+1 - L < 2) return;
	int pivot;
	switch (pivot_type) {
		case FIRST:
		{
			pivot = partition_first(arr, L, H);
		}
		case MEDIAN:
		{
			pivot = partition_median(arr, L, H);
		}
		case RANDOM:
		{
			pivot = partition_random(arr, L, H);
		}
	}
	if (pivot - L < H - pivot)
	{
		recursive_quicksort(pivot_type, arr, L, pivot-1);
		recursive_quicksort(pivot_type, arr, pivot+1, H);
	} else
	{
	/* Check right of current pivot */
	recursive_quicksort(pivot_type, arr, pivot+1, H);
	/* Check left of current pivot */
	recursive_quicksort(pivot_type, arr, L, pivot-1);
	}
}

/* ---------------------------------------------------------
 * Iterative quick sort implementation
 * --------------------------------------------------------- */
void iterative_quicksort(int pivot_type, int *arr, int L, int H)
{
	int top = -1;
	int stack[H - L + 1];
	stack[++top] = L;
	stack[++top] = H;

	while (top >= 0) {
		H = stack[top--];
		L = stack[top--];
		int pivot;
		switch (pivot_type) {
			case FIRST:
			{
				pivot = partition_first(arr, L, H);
			}
			case MEDIAN:
			{
				pivot = partition_median(arr, L, H);
			}
			case RANDOM:
			{
				pivot = partition_random(arr, L, H);
			}
		}

		if (pivot - 1 > L) {
			stack[++top] = L;
			stack[++top] = pivot - 1;
		}
		if (pivot + 1 < H) {
			stack[++top] = pivot + 1;
			stack[++top] = H;
		}
	}
}