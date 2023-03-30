#include <stdio.h>

int rekSum(int n);

int sum = 0;

int main()
{
    int n;
    do
    {
        printf("\n N=: ");
        scanf("%d", &n);
    } while (n < 1);
    printf("\n SUM=%d", rekSum(n));
    return 0;
}

int rekSum(int n)
{
    sum = sum + n;
    n--;
    if (n)
        return rekSum(n);
    return sum;
}