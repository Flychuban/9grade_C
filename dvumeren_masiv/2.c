#include <stdio.h>
const int maxbr = 100;
int main()
{
    int a[maxbr][maxbr], n1, n2, i, j,broqch=0;
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
            if (a[i][j]==1)
            {
                broqch++;
            }
            
        }
    }
    printf("\n Number '1' has been found %d times.", broqch);
    return 0;
}