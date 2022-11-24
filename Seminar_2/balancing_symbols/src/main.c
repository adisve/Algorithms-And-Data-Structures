#include <stdio.h>
#include <stdlib.h>
#include "../lib/balancing.h"


int main(void)
{

        char exp[100] = "{()}[[[[]]]]";

        if (balanced(exp))
                printf("Balanced \n");
        else
                printf("Not Balanced \n");
        return 0;
}