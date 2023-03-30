#include <stdio.h>

int main()
{
    int a[100], b[100], sum[100];
    int i, n;
    do
    {
        printf("\n Vuvedete broi chisla v masivite: ");
        scanf("%d", &n);
    } while (n < 1);
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo a[%d]= ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo b[%d]= ", i + 1);
        scanf("%d", &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum[i] = a[i] + b[i];
        printf("\n a[%d] + b[%d]= %d", i + 1, i + 1, sum[i]);
    }
    return 0;
}