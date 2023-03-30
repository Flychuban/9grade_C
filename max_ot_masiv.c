#include <stdio.h>

void main()
{
    float a[10], max;
    int i;
    printf("\n Chislo[1]= ");
    scanf("%f", &a[0]);
    max = a[0];

    for (i = 1; i < 10; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%f", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    printf("\n MAX=%.2f", max);
}