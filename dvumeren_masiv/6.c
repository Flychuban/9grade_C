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

    char zapis[maxlen];
    for (i = 1; i < n; i++)
    {
        j = i;
        while (strcmp(str[j], str[j - 1]) == -1 && j > 0)
        {
            strcpy(zapis, str[j]);
            strcpy(str[j], str[j - 1]);
            strcpy(str[j - 1], zapis);
            j--;
        }
    }
    found = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (strcmp(str[middle], turseno) == 0)
        {
            found = 1;
            break;
        }
        else if (strcmp(str[middle], turseno) < 0)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    if (found)
    {
        printf("\n Found!");
    }
    else
    {
        printf("\n Not Found!");
    }
    return 0;
}
