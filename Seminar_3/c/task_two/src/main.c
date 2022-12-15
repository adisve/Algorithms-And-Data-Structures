#include <stdio.h>
#include <stdlib.h>
#include "../lib/test_probing.h"
#include "../lib/test_chaining.h"

#define SIZE 7

int main(void)
{
        int input[SIZE] = { 4371, 1323, 6173, 4199, 4344, 9679, 1989 };
        printf("\n\n ---- Task two ----\n\n");
        a(input);
        b(input);
        c(input);

        return EXIT_SUCCESS;
}