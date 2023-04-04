#include <stdio.h>
#define maxbr_1 150
#define maxbr_2 50

int main()
{
    int a[maxbr_1], b[maxbr_2], c;
    int i, n, n2,n3, j, h;
    do
    {
        printf("\n Vuvedete broq na chislata v purviq masiv: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);
    do
    {
        printf("\n Vuvedete broq na chislata vuv vtoriq masiv: ");
        scanf("%d", &n2);
    } while (n2 < 1 || n2 > 50);
    for (i = 0; i < n; i++)
    {
        printf("\n a[%d]= ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n2; i++)
    {
        printf("\n b[%d]= ", i + 1);
        scanf("%d", &b[i]);
    }
    for (i = 1; i < n; i++)
    {
        j = i;
        while (a[j] < a[j - 1] && j > 0)
        {
            c = a[j];
            a[j] = a[j - 1];
            a[j - 1] = c;
            j--;
        }
    }
    n3=n+n2;
    for (i = 0; i < n2; i++)
    {
        n++;
        for (j = 0; j <= n && j<n3; j++)
        {
            if (b[i] < a[j])
            {
                for (h = n; h > j; h--)
                {
                    a[h] = a[h-1];
                }
                a[j] = b[i];
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    /*i = 0;
    n = n + n2;
    for (j; j < n; j++)
    {
        a[j] = b[i];
        i++;
    }
    for (i = 1; i < n; i++)
    {
        j = i;
        while (a[j] < a[j - 1] && j > 0)
        {
            c = a[j];
            a[j] = a[j - 1];
            a[j - 1] = c;
            j--;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    */
    return 0;
}