#ifndef GUARD
#define GUARD

typedef struct{
    int value;
    char errorflag;
} SafeResult;

SafeResult safeadd(int chislo_1, int chislo_2);
SafeResult safesubtract(int chislo_1, int chislo_2);
SafeResult safemultiply(int chislo_1, int chislo_2);
SafeResult safedivide(int chislo_1, int chislo_2);
SafeResult safestrtoint(char * mystr_chislo);

#endif