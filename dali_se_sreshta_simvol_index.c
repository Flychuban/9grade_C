#include <stdio.h>
#define maxbr 100

int main()
{
    int a[maxbr], i, n, j, c, found = 0, chislo;
    int l, r, middle, index;
    do
    {
        printf("\n Vuvedete broq na elementite v masiv: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);
    for (i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n Vuvedete turseno chislo: ");
    scanf("%d", &chislo);
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
    l = 0;
    r = n - 1;
    while (l <= r && !found)
    {
        middle = (l + r) / 2;
        if (a[middle] == chislo)
        {
            found = 1;
            index = middle;
        }
        else if (a[middle] > chislo)
        {
            r = middle - 1;
        }
        else
        {
            l = middle + 1;
        }
    }
    if (found)
    {
        printf("\n Index=%d", index);
    }
    else
    {
        printf("\n Index=-1");
    }
    return 0;
}