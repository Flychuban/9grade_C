#include <stdio.h>
const int maxbr = 100;
int main()
{
    int a[maxbr][maxbr],b[maxbr][maxbr], n1, n2, i, j,k,l;
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
    for ( i = 0; i < n2; i++)
    {
        printf("\n");
        for ( j = 0; j < n1; j++)
        {
            printf("%d ", a[j][i]);
        }
        
    }
    
    /*
    i=-1;
    for(k=0;k<n1;k++)
    {
        i++;
        j=-1;
        for ( l = 0; l < n2; l++)
        {
            j++;
            b[k][l]=a[i][j];
        }     
    }
    k=-1;
    for ( i = 0; i < n1; i++)
    {
        k++;
        l=-1;
        for( j = 0;j<n2;j++)
        {
            l++;
            a[j][i]=b[k][l];
            printf("%d", a[j][i]);
        }
    }
    
    for ( i = 0; i < n2; i++)
    {
        for ( j = 0; j < n1; j++)
        {
            if (j==0)
            {
                printf("\n %d", a[i][j]);
            }
            else
                printf(" %d", a[i][j]);
        }    
    }
    */
    return 0;
}