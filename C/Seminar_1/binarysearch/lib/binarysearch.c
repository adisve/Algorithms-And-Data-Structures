#include <stdio.h>
#include "binarysearch.h"


/* ---------------------------------------------------------
 * Implementation of Binary Sort algorithm.
 * A sorted array [arr] is required as input, repeatedly 
 * dividing the search interval in half. The algorithm checks
 * whether the [find] element is higher or lower than the current
 * middle, then only recursively performing another Binary Search
 * on the half that could contain this number. Partitioning of
 * this form is successively executed until the item is found in
 * the middle of a given partition, or until the interval is empty.
 * In the latter case, we return a -1, indicating false.
 * --------------------------------------------------------- */
int binarysearch(int *arr, int low, int high, int find)
{
        if (high >= low) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == find)
                        return mid;
        
                if (arr[mid] > find)
                        return binarysearch(arr, low, mid - 1, find);
                return binarysearch(arr, mid + 1, high, find);
        }
    return -1;
}