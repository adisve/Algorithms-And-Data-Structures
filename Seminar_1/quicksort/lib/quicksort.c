#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

#define CYCLES 10
#define RECURSIVE 0
#define ITERATIVE 1

/* Swap two elements pass by reference */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *arr, int L, int H) 
{
	/* Set pivot to be rightmost element in array */
	int pivot = arr[H];
	int pointer = (L - 1);

	/* Compare each element of array to pivot element */
	for (int i = L; i < H; i++) {
		if (arr[i] <= pivot) {
			/* Move pointer right in array */
			pointer++;
			swap(&arr[pointer], &arr[i]);
		}
	}
	/* Swap pivot with new greater element */
	swap(&arr[pointer + 1], &arr[H]);
	return (pointer + 1);
}

void quicksort(int *arr, int L, int H, int type) 
{
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
			break;
	}
	
}

/* Get median of three numbers (first, middle, last) */
int medianthree(int a, int b, int c)
{
	if ((a > b) ^ (a > c)) 
		return a;
	else if ((b < a) ^ (b < c)) 
		return b;
	else
		return c;
}

double median_three_quicksort(int *arr, int *reference_arr, int collection_size, int type)
{
	clock_t begin;
	clock_t end;
	/* Reset sorted list to be old version */
	for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];
	
	/* Median of three pivot test of quick sort algorithm */
	int pivot = medianthree(arr[0], arr[(collection_size-1)/2], arr[collection_size-1]);
	double time_spent;
	double avg_sum = 0;

	/* Execute for 10 cycles */
	for (int i = 0; i < CYCLES; i++)
	{
		begin = clock();
		quicksort(arr, 0, pivot, type);
		end = clock();
		printf("\nFinished quicksort iteration %d, with MEDIAN element as pivot\n", i+1);
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		avg_sum += time_spent;
		/* Reset sorted list to be old version */
		for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];
	}
	printf("\n----------------------------------------------------------\n");
	return avg_sum / CYCLES;
}

double random_quicksort(int *arr, int *reference_arr, int collection_size, int type)
{
	clock_t begin;
	clock_t end;
	/* Reset sorted list to be old version */
	for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];
	
	/* Random element pivot test of quick sort */
	int pivot = rand() % (collection_size);
	double time_spent;
	double avg_sum = 0;
	
	/* Execute for 10 cycles */
	for (int i = 0; i < CYCLES; i++)
	{
		begin = clock();
		quicksort(arr, 0, pivot, type);
		end = clock();
		printf("\nFinished quicksort iteration %d, with RANDOM element as pivot\n", i+1);
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		avg_sum += time_spent;
		/* Reset sorted list to be old version */
		for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];
	}
	printf("\n----------------------------------------------------------\n");
	return avg_sum / CYCLES;
}

double first_quicksort(int *arr, int *reference_arr, int collection_size, int type)
{
	clock_t begin;
			clock_t end;

	/* Reset sorted list to be old version */
	for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];

	/* First element index pivot test of quick sort */
	int pivot = 0;
	double time_spent;
	double avg_sum = 0;

	/* Execute for 10 cycles */
	for (int i = 0; i < CYCLES; i++) 
	{
		begin = clock();
		quicksort(arr, 0, pivot, type);
		end = clock();
		printf("\nFinished quicksort iteration %d, with FIRST element as pivot\n", i+1);
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		avg_sum += time_spent;
		/* Reset sorted list to be old version */
		for (int i = 0; i < collection_size; i++) arr[i] = reference_arr[i];
	}
	printf("\n----------------------------------------------------------\n");
	return avg_sum / CYCLES;
}