#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../lib/heap.h"

int main(void)
{
        srand(time(NULL));
        int arr[15] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
        minheap heap_insert = create();
        
        /* ---- Task 1 ---- */
        printf("Task 1.\n");
        
        for (int i = 0; i < 15; i++)
                insert(heap_insert, arr[i]);
        printf("\ta) -> After insertions:  ");
        levelorder(heap_insert);
                

        printf("\n");
        /* Build heap by giving array of items */
        minheap heap_heapified = heapify(arr, 15);
        printf("\tb) -> After heapification:  ");
        levelorder(heap_heapified);

        printf("\n");
        /* ---- Task 2 ---- */
        printf("\tc) \n");
        printf("\t   -> Preorder traversal array 1:  \n");
        preorder(heap_insert, 1);

        printf("\t   -> Preorder traversal array 2:  \n");
        preorder(heap_heapified, 1);

        destroy(heap_insert);
        destroy(heap_heapified);
        return EXIT_SUCCESS;
}
