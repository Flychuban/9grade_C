#include <stdio.h>

void proverka(int arr[], int arrSize);
int Prosto(int chislo);
int Is7(int chislo, int cifra);

int main()
{
    int arr[100], n;
    printf("\n Vuvedete broq na elementite: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\n Chislo[%d]= ", i + 1);
        scanf("%d", &arr[i]);
    }
    proverka(arr, n);
    return 0;
}

void proverka(int arr[], int arrSize)
{
    int cifra;
    printf("\n Vuvedete cifra koqto da se potursi dali se sreshta: ");
    scanf("%d", &cifra);
    for (int i = 0; i < arrSize; i++)
    {
        if (Prosto(arr[i]) && Is7(arr[i], cifra))
        {
            printf("%d ", arr[i]);
        }
    }
}

int Prosto(int chislo)
{
    for (int i = 2; i < chislo; i++)
    {
        if (chislo % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Is7(int chislo, int cifra)
{
    for (chislo; chislo > 0; chislo = chislo / 10)
    {
        if (chislo % 10 == cifra)
        {
            return 1;
        }
    }
    return 0;
}