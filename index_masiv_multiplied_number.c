#include <stdio.h>

int main()
{
    int a[100];
    int n, i;
    do
    {
        printf("\n Vuvedete broi chisla: ");
        scanf("%d", &n);
    } while (n < 1);
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%d", &a[i]);
        a[i] = a[i] * i;
    }
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= %d", i + 1, a[i]);
    }
    return 0;
}