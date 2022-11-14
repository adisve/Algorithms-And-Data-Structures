#include <stdio.h>

/* Get median of three numbers (first, middle, last) by
 * performing XOR operation comparing values */
int medianthree(int *arr, int a, int b, int c)
{
	
	if ((arr[a] <= arr[b]) && (arr[b] <= arr[c])) return b;
    if ((arr[a] <= arr[c]) && (arr[c] <= arr[b])) return c;
    if ((arr[b] <= arr[a]) && (arr[a] <= arr[c])) return a;
    if ((arr[b] <= arr[c]) && (arr[c] <= arr[a])) return c;
    if ((arr[c] <= arr[a]) && (arr[a] <= arr[b])) return a;
    return b;
}