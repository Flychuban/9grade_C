#include <stdio.h>

int recBinary(int chislo);

int res = 0;
int c = 1;
int main()
{

    const int res = 0, c = 1;
    int chislo;
    do
    {
        printf("\n Decimal number: ");
        scanf("%d", &chislo);
    } while (chislo < 0);
    printf("\n %d", recBinary(chislo));
    return 0;
}

int recBinary(int chislo)
{
    if (chislo)
    {
        res = res + (chislo % 2) * c;
        c = c * 10;
        return recBinary(chislo / 2);
    }
    return res;
}