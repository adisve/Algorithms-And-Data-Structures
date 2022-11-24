#include "balancing.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1

static char balancing_brackets[] = {
        '[', ']',
        '{', '}',
        '(', ')',
};

int balanced(char *data)
{
        /* Expression is empty, valid */
        if (data[0] == '\0') return SUCCESS;

        struct stacknode* stack = NULL;

        for (int i = 0; i < strlen(data); i++) {
                /* If data[i] is an opening bracket, push it to the stack */
                if (data[i] == balancing_brackets[0] || data[i] == balancing_brackets[2] || data[i] == balancing_brackets[4])
                        push(&stack, data[i]);
                
                /* If data[i] is an enclosing bracket, pop and compare */
                if (data[i] == balancing_brackets[1] || data[i] == balancing_brackets[3] || data[i] == balancing_brackets[5])
                {
                        if (stack == NULL) return ERROR;
                        if (!match(pop(&stack), data[i])) return ERROR;
                }               
        }
        if (stack == NULL) return SUCCESS;
        return ERROR;
}

int match(char x, char y)
{               
        if (x == balancing_brackets[0] && y == balancing_brackets[1])
        {
                printf("\nSuccess: Open: %c, Close: %c\n", x, y);
                return SUCCESS;
        }
        else if (x == balancing_brackets[2] && y == balancing_brackets[3])
        {
                printf("\nSuccess: Open: %c, Close: %c\n", x, y);
                return SUCCESS;
        }
        else if (x == balancing_brackets[4] && y == balancing_brackets[5])
        {
                printf("\nSuccess: Open: %c, Close: %c\n", x, y);
                return SUCCESS;
        }     
        printf("\nError. Enclosing characters do not match: Open: %c, Close: %c\n", x, y);
        return ERROR;
}