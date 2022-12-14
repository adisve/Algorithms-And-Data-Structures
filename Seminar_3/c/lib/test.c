#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "heap.h"

void a(minheap heap)
{
        printf("Task 1.\n");
        printf("\ta) -> After insertions:  ");
        levelorder(heap);
}

void b(minheap heap)
{
        printf("\n\tb) -> After heapification:  ");
        levelorder(heap);
}

void c(minheap heap_one, minheap heap_two, int i)
{
        printf("\n");
        printf("\tc) \n");
        printf("\t   -> Preorder traversal array 1:  ");
        preorder(heap_one, 1);
        printf("\n");
        printf("\t   -> Preorder traversal array 2:  ");
        preorder(heap_two, 1);
        printf("\n\n");
        printf("\t   -> In order traversal array 1: ");
        inorder(heap_one, 1);
        printf("\n");
        printf("\t   -> In order traversal array 2: ");
        inorder(heap_two, 1);
        printf("\n\n");
        printf("\t   -> Post order traversal array 1: ");
        postorder(heap_one, 1);
        printf("\n");
        printf("\t   -> Post order traversal array 2: ");
        postorder(heap_two, 1);
        printf("\n\n");
        printf("\t   -> Level order traversal array 1: ");
        levelorder(heap_one);
        printf("\n");
        printf("\t   -> Level order traversal array 2: ");
        levelorder(heap_two);
        printf("\n");
}