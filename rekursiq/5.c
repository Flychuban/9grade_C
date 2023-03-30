#include <stdio.h>
#define MaxN 100

int rekBinSearch(int arr[], int turseno, int left, int right);

int main()
{
    int n;
    int arr[MaxN];
    do
    {
        printf("\n N: ");
        scanf("%d", &n);
    } while (n < 1 || n > MaxN);
    for (int i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%d", &arr[i]);
    }
    int turseno;
    printf("\n Turseno chislo: ");
    scanf("%d", &turseno);
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1] && j > 0)
        {
            int c = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = c;
            j--;
        }
    }
    int left = 0;
    int right = n - 1;
    if (rekBinSearch(arr, turseno, left, right))
    {
        printf("\n Tova chislo se sreshta!");
    }
    else
    {
        printf("\n Tova chislo NE se sreshta!");
    }
    return 0;
}

int rekBinSearch(int arr[], int turseno, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    int middle = (left + right) / 2;
    if (arr[middle] == turseno)
    {
        return 1;
    }
    else if (arr[middle] < turseno)
    {
        return rekBinSearch(arr, turseno, middle + 1, right);
    }
    else
    {
        return rekBinSearch(arr, turseno, left, middle - 1);
    }
}