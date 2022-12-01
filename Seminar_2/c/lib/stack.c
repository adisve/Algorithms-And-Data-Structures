#include <stdio.h>
#include <stdlib.h>
#include "../lib/balancing.h"
#include "stack.h"

struct stacknode;

/**
 * @brief Implementation of stack push function on struct
 * of type stacknode.
 * 
 * @param stack_top -> address of &stack
 * @param val -> value to add
 */
void push(struct stacknode** stack_top, int val)
{
        /* Create new node to push to stack */
        struct stacknode* node = (struct stacknode*)malloc(sizeof(struct stacknode));

        /* Check for stack overflow error */
        if (node == NULL) stackoverflow_error();
        
        node->val = val;
        node->nextnode = *stack_top;
        *stack_top = node;
}

/**
 * @brief Implementation of stack pop function on struct
 * of type stacknode.
 * 
 * Takes address of &stack as parameter, serving as
 * the top of the stack.
 *
 * @return x -> the value of the newly added stack element.
 */
int pop(struct stacknode** stack_top)
{
        char x;
        struct stacknode* top;
        if (*stack_top == NULL) return -1;

        top = *stack_top;
        x = top->val;
        *stack_top = top->nextnode;
        free(top);
        return x;
}

void stackoverflow_error()
{
        printf("\nStack overflow error\n");
        exit(0);
}