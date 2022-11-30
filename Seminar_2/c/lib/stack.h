#ifndef STACK_HEADER
#define STACK_HEADER

struct stacknode {
        /* The stored expression char */
        char val;
        /* Pointer to next node in stack */
        struct stacknode* nextnode;
};

int pop(struct stacknode** top);
void push(struct stacknode** top, int val);
void stackoverflow_error();

#endif