#include <stdio.h>
#define MAXBR 100

int Permutation(int arr[], int n);

int main()
{
    int n;
    int arr[MAXBR];
    do
    {
        printf("\n Vuvedete broq na chislata v masiva: ");
        scanf("%d", &n);
    } while (n < 0 || n > MAXBR);
    for (int i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
    Permutation(arr, n);
    return 0;
}

int Permutation(int arr[], int n)
{
    /*int faktoriel=1;
    int i;
    for ( i = 1; i <= n; i++)
    {
        faktoriel=faktoriel*i;
    }
    */
    while (n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("  ");
            printf("%d", arr[i]);
        }
        n--;
    }
}