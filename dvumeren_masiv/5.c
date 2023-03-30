#include <stdio.h>
#include <string.h>

const int maxbr = 100;
const int maxlen = 10;

int main()
{
    char str[maxbr][maxlen], *p, turseno[maxlen], found = 0;
    int i, n, j;
    do
    {
        printf("\n Number of names: ");
        scanf("%d", &n);
        getchar();
    } while (n < 1 || n > maxbr);
    for (i = 0; i < n; i++)
    {
        printf("\n Name less than 10 symbols: ");
        fgets(str[i], 9, stdin);
        if (p = strchr(str[i], '\n'))
            *p = '\0';
    }
    printf("\n Turseno ime po malko ot 10 symbols: ");
    fgets(turseno, 9, stdin);
    if (p = strchr(turseno, '\n'))
        *p = '\0';
    for (i = 0; i < n; i++)
    {
        if (strstr(str[i], turseno))
        {
            printf("\n Found!");
            return 0;
        }
    }
    printf("\n Not found!");
    return 0;
}