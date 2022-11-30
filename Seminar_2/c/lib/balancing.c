#include "balancing.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1


int balanced(char *data)
{
        /* Expression is empty, valid */
        if (data[0] == '\0') return SUCCESS;
        int inComment = 0;

        struct stacknode* stack = NULL;

        for (int i = 0; i < strlen(data); i++) 
        {
                if (data[i] == '/' && data[i+1] == '/')
                {
                        break;
                }

                /* No brackets can be added after full line comment */
                if ((data[i] == '*' && data[i+1] == '/') && !inComment)
                {
                        printf("\nInvalid syntax: Ending comment requires '/*' prior\n");
                        return ERROR;
                }

                /* Detect opening comment */
                if ((data[i] == '/' && data[i+1] == '*'))
                {
                        push(&stack, data[i]);
                        push(&stack, data[i+1]);
                        inComment = 1;
                }

                /* Detect closing comment */
                if (data[i] == '*' && data[i+1] == '/')
                {
                        inComment = 0;
                        if (stack == NULL)
                        {
                                printf("\nMissing closing comment");
                                return ERROR;
                        }
                        
                        if (!(pop(&stack) == '*' && pop(&stack) == '/'))
                        {
                                printf("\nMissing closing comment");
                                return ERROR;
                        }

                }

                if (!inComment)
                {
                        /* Detect opening brackets */
                        if ((data[i] == '[' || data[i] == '{' || data[i] == '(') && !inComment)
                                push(&stack, data[i]);
                        /* Detect closing brackets */
                        if ((data[i] == ']' || data[i] == '}' || data[i] == ')') && !inComment)
                        {
                                if (stack == NULL) return ERROR;
                                if (!match(pop(&stack), data[i]))
                                {
                                        printf("\nSyntax error: The symbol '%c' is missing a beginning character \n", data[i]);
                                        return ERROR;
                                }
                        }
                }         
        }
        if (stack == NULL) return SUCCESS;

        char bracket = pop(&stack);
        while (bracket != -1)
        {
                if (bracket == '*')
                {
                        printf("\nSyntax error: The symbol '%c%c' is missing its closing comment '*/' \n", pop(&stack), bracket);
                        bracket = pop(&stack);
                        continue;
                }
                printf("\nSyntax error: The symbol '%c' is missing an ending character \n", bracket);
                bracket = pop(&stack);
        }
        return ERROR;
}

int match(char x, char y)
{               
        if (x == '[' && y == ']')
        {
                return SUCCESS;
        }
        else if (x == '{' && y == '}')
        {
                return SUCCESS;
        }
        else if (x == '(' && y == ')')
        {
                return SUCCESS;
        }     
        return ERROR;
}