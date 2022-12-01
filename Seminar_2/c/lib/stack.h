#ifndef STACK_HEADER
#define STACK_HEADER

struct node {
        /* The stored expression char */
        char val;
        /* Pointer to next node in stack */
        struct node* nextnode;
};

int pop(struct node** top);
void push(struct node** top, int val);
void stackoverflow_error();

#endif