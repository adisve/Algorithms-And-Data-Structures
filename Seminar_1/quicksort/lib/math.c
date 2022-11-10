#include <stdio.h>

/* Get median of three numbers (first, middle, last) by
 * performing XOR operation comparing values */
int medianthree(int a, int b, int c)
{
	if ((a > b) ^ (a > c)) 
		return a;
	else if ((b < a) ^ (b < c)) 
		return b;
	else
		return c;
}