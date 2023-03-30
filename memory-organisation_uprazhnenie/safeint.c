#include "safeint.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

SafeResult safeadd(int chislo_1, int chislo_2){
    SafeResult p;
    p.errorflag = '0';

    long long result = chislo_1 + chislo_2;
    if (result > INT_MAX || result < INT_MIN)
    {
        p.errorflag = '1';
        return p;
    }
    p.value = result;
    return p;
}

SafeResult safesubtract(int chislo_1, int chislo_2){
    SafeResult p;
    p.errorflag = '0';

    long long result = chislo_1 - chislo_2;
    if (result > INT_MAX || result < INT_MIN)
    {
        p.errorflag = '1';
        return p;
    }
    p.value = result;
    return p;
}

SafeResult safemultiply(int chislo_1, int chislo_2){
    SafeResult p;
    p.errorflag = '0';

    long long result = chislo_1 * chislo_2;
    if (result > INT_MAX || result < INT_MIN)
    {
        p.errorflag = '1';
        return p;
    }
    p.value = result;
    return p;
}

SafeResult safedivide(int chislo_1, int chislo_2){
    SafeResult p;
    p.errorflag = '0';
    long long result = chislo_1 / chislo_2;
    if (result > INT_MAX || result < INT_MIN)
    {
        p.errorflag = '1';
        return p;
    }

    p.value = result;
    return p;
}

SafeResult safestrtoint(char *mystr_chislo){
    SafeResult p;
    int length = strlen(mystr_chislo);
    long long chislo_int = 0;
    int number_started = 0; // tova proverqva za '-' ako e v nachaloto
    int minus_flag = 0;
    int flag_error = 0;
    for (int i = 0; i < length; i++)
    {
        char symbol = mystr_chislo[i];
        if (!number_started)
        {
            if (symbol == '-')
            {
                minus_flag = 1;
                number_started = 1;
            }
            else if (symbol >= '0' && symbol <= '9')
            {
                chislo_int = chislo_int * 10 + (symbol - 48); // -48 ascii table char -> int
                number_started = 1;
            }
            else
            {
                flag_error = 1;
                break;
            }
        }
        else
        {
            if (symbol >= '0' && symbol <= '9')
            {
                chislo_int = chislo_int * 10 + (symbol - 48);
            }
            else
            {
                flag_error = 1;
                break;
            }
        }
    }

    if (flag_error)
    {
        printf("Invalid input string! \n");
        p.errorflag = '1';
        return p;
    }
    else
    {
        if (minus_flag)
        {
            chislo_int = chislo_int * (-1);
        }

        p.value = chislo_int;
    }
    if (chislo_int > INT_MAX || chislo_int < INT_MIN)
    {
        p.errorflag = '1';
        return p;
    }
    return p;
}