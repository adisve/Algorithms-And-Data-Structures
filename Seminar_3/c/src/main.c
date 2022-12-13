#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/heap.h"

int main(void)
{
        srand(time(NULL));
        minheap heap = buildheap();
        char arr[15] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
        for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
        {
                printf("Inserting number %d\n", arr[i]);
                insert(heap, arr[i]);
        }
        while (!isempty(heap))
        {
                printf("%4d", findmin(heap));
                deletemin(heap);
        }
        destroy(heap);
        return EXIT_SUCCESS;
}