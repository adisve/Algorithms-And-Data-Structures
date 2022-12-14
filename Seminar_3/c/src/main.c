#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../lib/heap.h"
#include "../lib/task_one.h"

int main(void)
{
        srand(time(NULL));
        int arr[15] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
        minheap heap_one = create();
        minheap heap_two = heapify(arr, 15);
        
        for (int i = 0; i < 15; i++)
                insert(heap_one, arr[i]);

        a(heap_one);
        b(heap_two);
        c(heap_one, heap_two, 1);
        d();

        destroy(heap_one);
        destroy(heap_two);
        return EXIT_SUCCESS;
}
