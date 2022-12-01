#include <stdio.h>
#include <stdlib.h>
#include "../lib/balancing.h"

void runtest(char *exp);

static char *validtests[] = {
        /* C */
        "int a",
        "int a; /* random comment */",
        "int a; /* for storing width * height */",
        "int a = b*c;",
        "int a = b / c;",
        "int a = 55; // This is a comment / [ ",
        "public void doIt(int x) {System.out.println(x*100);}",
        "int []arr = new int[10];",
        "/* */ {}",

        /* C++ */
        "if(a == b) {a++;}",
        "if(a < (b*c)) {t = 5;}",
        "int []b = new int[5];",
        "[](){}",
        "int a = 5; // init a to 5",
};

static char *invalidtests[] = {
        /* C */
        "int [arr = new int[10];",
        "int b = 5; /* this is a comment /",
        "{a=b;",
        "}",

        /* C++ */
        "for(int i=0;i<10;i++] {a+= b;}",
        "{abc)"
};



/**
 * @brief C program to verify integrity of strings written in
 * the C and C++ program languages 
 * 
 * @return int 
 */
int main(void)
{
        for (int i = 0; i < sizeof(validtests) / sizeof(validtests[0]); i++) {
                /* Should be valid for all */
                balanced(validtests[i]);
        }

        for (int i = 0; i < sizeof(invalidtests) / sizeof(invalidtests[0]); i++) {
                /* Should be invalid for all */
                balanced(invalidtests[i]);
        }
        return 0;
}