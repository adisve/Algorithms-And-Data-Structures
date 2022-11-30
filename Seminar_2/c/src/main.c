#include <stdio.h>
#include <stdlib.h>
#include "../lib/balancing.h"


int main(void)
{

        char exp[100] = "int b = 5; /* this is a comment / ";

        if (balanced(exp))
                printf("\nValid \n");
        else
                printf("\nNot valid \n");
        return 0;
}