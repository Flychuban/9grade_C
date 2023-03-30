#include <stdio.h>

int main()
{
    int n, i, j;
    float a[100], c;
    do
    {
        printf("\n Vuvedete broi chisla: ");
        scanf("%d", &n);
    } while (n < 1);
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%f", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        j = i;
        while (a[j - 1] < a[j] && j > 0)
        {
            c = a[j];
            a[j] = a[j - 1];
            a[j - 1] = c;
            j--;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    return 0;
}