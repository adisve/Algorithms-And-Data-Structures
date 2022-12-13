#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/heap.h"

void printheap(minheap heap);

int main(void)
{
        srand(time(NULL));
        int arr[15] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
        minheap heap_insert = create(arr);
        
        /* Build heap by inserting items one by one */
        for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
        {
                printf("Inserting number %d\n", arr[i]);
                insert(heap_insert, arr[i]);
        }
        printheap(heap_insert);

        /* Build heap by giving array of items */
        minheap heap_heapified = buildheap(arr, sizeof(arr)/sizeof(arr[0]));
        printheap(heap_heapified);

        return EXIT_SUCCESS;
}

void printheap(minheap heap)
{
        while (!isempty(heap))
        {
                printf("%4d", findmin(heap));
                deletemin(heap);
        }
        printf("\n");
        destroy(heap);
}