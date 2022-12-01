#include <stdio.h>
#include <stdlib.h>
#include "../lib/balancing.h"
#include "stack.h"

struct node;

/**
 * @brief: Implementation of stack push function on struct
 * of type stacknode.
 * 
 * @param stack_top: top node in stack
 * @param val: value to add
 */
void push(struct node** stack_top, int val)
{
        /* Create new node to push to stack */
        struct node* node = (struct node*)malloc(sizeof(struct node));

        /* Check for stack overflow error */
        if (node == NULL) stackoverflow_error();
        
        node->val = val;
        node->nextnode = *stack_top;
        *stack_top = node;
}

/**
 * @brief: Implementation of stack pop function on struct
 * of type stacknode.
 * 
 * @param stack_top: top node in stack
 *
 * @return x: the value of the newly added stack element.
 */
int pop(struct node** stack_top)
{
        char x;
        struct node* top;
        if (*stack_top == NULL) return -1;

        top = *stack_top;
        x = top->val;
        *stack_top = top->nextnode;
        free(top);
        return x;
}

/**
 * @brief: error message on stack overflow
 */
void stackoverflow_error()
{
        printf("\nStack overflow error\n");
        exit(0);
}