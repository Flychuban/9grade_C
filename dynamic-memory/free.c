#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    float *p = (float *)malloc(sizeof(float));

    *p = 10;
    printf("%f", *p);

    free(p);
    printf("\n%f", *p);

    return 0;
}