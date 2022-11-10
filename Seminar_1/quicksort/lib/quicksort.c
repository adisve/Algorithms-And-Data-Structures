#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

/* Swap two elements pass by reference */
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int arr[], int L, int H) 
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

void recursive_quicksort(int arr[], int L, int H) 
{
  if (L < H) {
    int pivot = partition(arr, L, H);
    /* Check left of current pivot */
    recursive_quicksort(arr, L, pivot-1);
    /* Check right of current pivot */
    recursive_quicksort(arr, pivot+1, H);
  }
}