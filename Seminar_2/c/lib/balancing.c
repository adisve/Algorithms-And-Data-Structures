#include "balancing.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define SUCCESS 1

/**
 * @brief: check if character array has valid
 * opening and closing character combinations
 * 
 * @param data: character expression
 * @return int: valid or not valid
 */
int balanced(char *data)
{
        /* If expression is empty, return valid */
        if (data[0] == '\0') return SUCCESS;

        int inComment = 0;
        struct node* top = NULL;

        for (int i = 0; i < strlen(data); i++) 
        {
                if (!inComment)
                {
                        /**
                         * If the supplied characters are beginning of
                         * a single-line comment, no new characters can be
                         * added to the stack since they will not be registered
                         * by the compiler. 
                         * */
                        if (data[i] == '/' && data[i+1] == '/')
                        {
                                break;
                        }

                        /* Detect multi-line comment opening characters */
                        if ((data[i] == '/' && data[i+1] == '*'))
                        {
                                push(&top, data[i]);
                                push(&top, data[i+1]);
                                inComment = 1;
                        }

                        /* Detect opening brackets */
                        if ((data[i] == '[' || data[i] == '{' || data[i] == '(') && !inComment)
                                push(&top, data[i]);

                        /* Detect closing brackets */
                        if ((data[i] == ']' || data[i] == '}' || data[i] == ')') && !inComment)
                        {
                                if (top == NULL || !match(pop(&top), data[i]))
                                {
                                        missingOpeningCharacterError(data[i]);
                                        return ERROR;
                                }
                        }
                }      
                else
                {
                        /* Detect multi-line comment closing characters */
                        if (data[i] == '*' && data[i+1] == '/')
                        {
                                if (top == NULL || !(pop(&top) == '*' && pop(&top) == '/'))
                                {
                                        missingOpeningCommentError();
                                        return ERROR;
                                }
                        }
                }   
        }
        
        if (top == NULL)
        {
                validInputSuccess();
                return SUCCESS;
        }

        char bracket = pop(&top);
        while (bracket != -1)
        {
                if (bracket == '*')
                {
                        missingClosingCommentError();
                        bracket = pop(&top);
                        continue;
                }
                missingClosingCharacterError(bracket);
                bracket = pop(&top);
        }
        return ERROR;
}

/**
 * @brief match enclosing characters
 * 
 * @param x: top item in stack
 * @param y: closing char
 * @return int: match or no match
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

/**
 * @brief: error message for missing closing char
 * @param c: char perpetrator
 */
void missingClosingCharacterError(char c)
{
        printf("\n[Invalid syntax] Reason: The symbol '%c' is missing its closing character\n", c);
}

/**
 * @brief: error message for missing opening char
 * @param c: char perpetrator
 */
void missingOpeningCharacterError(char c)
{
        printf("\n[Invalid syntax] Reason: The symbol '%c' is missing its opening character\n", c);
}

/**
 * @brief: error message for missing closing multi-line comment
 */
void missingClosingCommentError()
{
        printf("\n[Invalid syntax] Reason: The symbol '/*' is missing its closing comment '*/' \n");
}

/**
 * @brief: error message for missing opening multi-line comment
 */
void missingOpeningCommentError()
{
        printf("\n[Invalid syntax] Reason: The symbol '*/' is missing its closing comment '/*' \n");
}

/**
 * @brief: message on successful string parsing
 */
void validInputSuccess()
{
        printf("\n[Valid syntax]\n");
}