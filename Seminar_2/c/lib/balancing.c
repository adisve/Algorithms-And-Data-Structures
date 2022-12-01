#include "balancing.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1

/**
 * @brief check if character array has valid
 * opening and closing character combinations
 * 
 * @param data -> character expression
 * @return int -> valid or not valid
 */
int balanced(char *data)
{
        /* If expression is empty, return valid */
        if (data[0] == '\0') return SUCCESS;

        int inComment = 0;
        struct stacknode* stack = NULL;

        for (int i = 0; i < strlen(data); i++) 
        {
                /**
                 * If the supplied characters are beginning of
                 * a simple comment, no new characters can be
                 * added to the stack since it will not be registered
                 * by the compiler */
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

                /* Detect multi-line comment opening characters */
                if ((data[i] == '/' && data[i+1] == '*'))
                {
                        push(&stack, data[i]);
                        push(&stack, data[i+1]);
                        inComment = 1;
                }

                /* Detect multi-line comment closing characters */
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

/**
 * @brief match enclosing characters
 * 
 * @param x -> top item in stack
 * @param y -> closing char
 * @return int -> match or no match
 */
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