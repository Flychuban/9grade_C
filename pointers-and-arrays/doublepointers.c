#include <stdio.h>

int main(void)
{

    int a = 15;
    int *p = &a; //*p == 15 int variable
    int **pp = &p;
    // int * pp2 = &p; //*pp2 != pointer

    printf("&a=%p\n", &a);
    printf("p=%p\n", p);
    printf("&p=%p\n", &p);
    printf("pp=%p\n", pp);
    printf("&pp=%p\n", &pp);

    printf("*p=%d\n", *p);
    printf("*pp=%p\n", *pp);
    printf("**pp=%d\n", **pp);

    return 0;
}