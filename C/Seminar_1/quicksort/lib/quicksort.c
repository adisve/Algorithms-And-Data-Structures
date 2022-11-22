#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#include "measurement.h"

#define CYCLES 	10
#define CUTOFF	10
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
 * Dynamically return pivot based on P_TYPE parameter
 * --------------------------------------------------------- */
int p_type(int *arr, int L, int H, int P_TYPE)
{
	if (P_TYPE == FIRST) 
	{
		swap(&arr[H], &arr[L]);
		return arr[H];
	}

	else if (P_TYPE == MEDIAN) return median_pivot(arr, L, H);

	return random_pivot(arr, L, H);
}

/* ---------------------------------------------------------
 * Median element partitioning.
 * --------------------------------------------------------- */
int median_pivot(int* arr, int L, int H) {
	/* Find index of middle element in sub section */
	int M = (L + H) / 2;

	/* If the middle element is smaller than the one on
	 * the far left, swap their positions */
	if (arr[M] < arr[L]) 
		swap(&arr[L], &arr[M]);
	/* If the element on the far right is smaller than the
	 * element on the far left the far left, swap their positions */
	if (arr[H] < arr[L])
		swap(&arr[L], &arr[H]);
	/* If the element on the far right is smaller than the
	 * element in the middle, swap their places */
	if (arr[H] < arr[M])
		swap(&arr[M], &arr[H]);
	/* Swap places with the middle element and the element
	 * on the left of the far right element in the array */
	swap(&arr[M], &arr[H-1]);
	return arr[H];
}

/* ---------------------------------------------------------
 * Random element partitioning.
 * --------------------------------------------------------- */
int random_pivot(int *arr, int L, int H)
{
	int random = (rand() % (H - L + 1)) + L;
	swap(&arr[random], &arr[H]);
	return arr[H];
}

/* ---------------------------------------------------------
 * Partition function (Lomuto's)
 * --------------------------------------------------------- */
int partition(int *arr, int L, int H, int P_TYPE)
{
	int pivot = p_type(arr, L, H, P_TYPE);
	int i = (L - 1);

	for (int j = L; j <= H - 1; j++)
	{
		if (arr[j] <= pivot) 
			swap(&arr[++i], &arr[j]);
	}
	swap(&arr[i + 1], &arr[H]);
	return (i + 1);
}

/* ---------------------------------------------------------
 * Recursive quick sort implementation
 * --------------------------------------------------------- */
void r_qsort(int P_TYPE, int *arr, int L, int H) 
{
	if (L < H)
	{
		int i = partition(arr, L, H, P_TYPE);
		r_qsort(P_TYPE, arr, L, i - 1);
		r_qsort(P_TYPE, arr, i + 1, H);
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
		int p = partition(arr, L, H, P_TYPE);
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