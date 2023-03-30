#include <stdio.h>
const int maxbr = 100;
int main()
{
    int a[maxbr][maxbr], n1, n2, i, j;
    do
    {
        printf("\n Number rows: ");
        scanf("%d", &n1);
    } while (n1 < 0 || n1 > maxbr);
    do
    {
        printf("\n Number columns: ");
        scanf("%d", &n2);
    } while (n2 < 0 || n2 > maxbr);
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("\n Number[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (j == 0)
            {
                printf("\n %d", a[i][j]);
            }
            else
                printf(" %d", a[i][j]);
        }
    }

    return 0;
}