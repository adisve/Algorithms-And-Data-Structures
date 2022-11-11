#include "binarysearch.h"
#include <stdio.h>

int binarysearch(int *arr, int low, int high, int element)
{
        if (high >= low) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == element)
                        return mid;
        
                if (arr[mid] > element)
                        return binarysearch(arr, low, mid - 1, element);
                return binarysearch(arr, mid + 1, high, element);
        }
    return -1;
}