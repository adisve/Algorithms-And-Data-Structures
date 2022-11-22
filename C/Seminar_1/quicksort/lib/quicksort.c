#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#include "measurement.h"

#define CYCLES 10
#define MEDIAN  0
#define FIRST   1
#define RANDOM  2

/* ---------------------------------------------------------
 * Swaps two elements in array by reference.
 * --------------------------------------------------------- */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


/* ---------------------------------------------------------
 * Last element partitioning. Used with [p_median]
 * and [p_random] after performing swapping of pivots.
 * --------------------------------------------------------- */
int p_last(int *arr, int L, int H)
{
	int pivot = arr[H];
	int pointer = (L - 1);

	for (int j = L; j < H; j++) {
		if (arr[j] < pivot) {
			swap(&arr[++pointer], &arr[j]);
		}
	}

	swap(&arr[pointer + 1], &arr[H]);
	return (pointer + 1);
}


/* ---------------------------------------------------------
 * First element partitioning.
 * --------------------------------------------------------- */
int p_first(int *arr, int L, int H) 
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

/* ---------------------------------------------------------
 * Median element partitioning.
 * --------------------------------------------------------- */
int p_median(int* arr, int L, int H) {
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
	return p_last(arr, L, H);
}

/* ---------------------------------------------------------
 * Random element partitioning.
 * --------------------------------------------------------- */
int p_random(int *arr, int L, int H)
{
	int random = (rand() % (H - L + 1)) + L;
	swap(&arr[random], &arr[H]);

	return p_last(arr, L, H);
}

/* ---------------------------------------------------------
 * Recursive quick sort implementation
 * --------------------------------------------------------- */
void r_qsort(int P_TYPE, int *arr, int L, int H) 
{
	if (L < H) {
		int pivot = p_type(arr, L, H, P_TYPE);
		
		/* Check left of current pivot */
		r_qsort(P_TYPE, arr, L, pivot-1);
		/* Check right of current pivot */
		r_qsort(P_TYPE, arr, pivot+1, H);
	}
}

/* ---------------------------------------------------------
 * Iterative quick sort implementation
 * --------------------------------------------------------- */
void i_qsort(int P_TYPE, int *arr, int L, int H)
{
	int top = -1;
	int stack[H - L + 1];
	stack[++top] = L;
	stack[++top] = H;

	while (top >= 0) {
		H = stack[top--];
		L = stack[top--];
		int pivot = p_type(arr, L, H, P_TYPE);

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

/* ---------------------------------------------------------
 * Dynamically return pivot based on P_TYPE parameter
 * --------------------------------------------------------- */
int p_type(int *arr, int L, int H, int P_TYPE)
{
	if (P_TYPE == FIRST) return p_first(arr, L, H);

	else if (P_TYPE == MEDIAN) return p_median(arr, L, H);

	return p_random(arr, L, H);
}