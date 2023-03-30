#include <stdio.h>
#define maxbr 100

int main()
{
    int a[maxbr];
    int i, n, j, c, broqch = 0;
    do
    {
        printf("\n Vuvedete broi chisla: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        j = i;
        while (a[j - 1] > a[j] && j > 0)
        {
            c = a[j];
            a[j] = a[j - 1];
            a[j - 1] = c;
            j--;
        }
    }
    i=0;
    printf("%d ",a[i]);   
    for (i = 1; i < n; i++)
    {
        if (a[i - 1] != a[i])
        {
            printf("%d ", a[i]);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
        {
            broqch++;
        }
    }
    printf("\n Broqt na razlichnite chisla e: %d", broqch);
    return 0;
}