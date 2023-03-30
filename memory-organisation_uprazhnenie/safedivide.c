#include <stdio.h>
#include "safeint.h"

int main(int *argc, char **argv)
{
    int chislo_1, chislo_2;
    SafeResult chislo = safestrtoint(argv[1]);
    if (chislo.errorflag == '1')
    {
        printf("Overflow error! Write new numbers");
        return 0;
    }
    else
    {
        chislo_1 = chislo.value;
    }

    chislo = safestrtoint(argv[2]);
    if (chislo.errorflag == '1')
    {
        printf("Overflow error! Write new numbers");
        return 0;
    }
    else
    {
        chislo_2 = chislo.value;
    }

    SafeResult result = safedivide(chislo_1, chislo_2);
    if (result.errorflag == '1')
    {
        printf("Overflow error! Write new numbers");
    }
    else
    {
        printf("Result: %d", result.value);
    }
    return 0;
}