#include <stdio.h>

/* Get median of three numbers (first, middle, last) by
 * performing XOR operation comparing values */
int medianthree(int *arr, int a, int b, int c)
{
	if ((arr[a] > arr[b]) ^ (arr[a] > arr[c])) 
		return a;
	else if ((arr[b] < arr[a]) ^ (arr[b] < arr[c])) 
		return b;
	else
		return c;
}