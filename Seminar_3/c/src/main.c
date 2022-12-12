#include <stdio.h>
#include <stdlib.h>
#include "../lib/heap.h"

int main(void)
{
        int size = 0;
        int arr[10];
        insert(arr, 1, &size);
        insert(arr, 2, &size);
        insert(arr, 3, &size);
        insert(arr, 4, &size);
        insert(arr, 5, &size);
        insert(arr, 6, &size);
        insert(arr, 7, &size);
        insert(arr, 8, &size);
        insert(arr, 9, &size);
        insert(arr, 10, &size);
        insert(arr, 11, &size);
        insert(arr, 12, &size);
        insert(arr, 13, &size);
        insert(arr, 14, &size);
        insert(arr, 15, &size);

        for (int i = 0; i < size; ++i)
                printf("%d ", arr[i]);
        printf("\n");

        return EXIT_SUCCESS;
}