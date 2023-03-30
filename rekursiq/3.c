#include <stdio.h>

int nodEuclid(int chislo1, int chislo2);

int main()
{
    int chislo1, chislo2;
    do
    {
        printf("\n 1st number: ");
        scanf("%d", &chislo1);
    } while (chislo1 < 1);
    do
    {
        printf("\n 2nd number: ");
        scanf("%d", &chislo2);
    } while (chislo2 < 1);
    printf("\n Nai golemiq delitel e: %d", nodEuclid(chislo1, chislo2));
    return 0;
}

int nodEuclid(int chislo1, int chislo2)
{
    if (chislo2)
    {
        return (chislo2, chislo1 % chislo2);
    }
    return chislo1;
}