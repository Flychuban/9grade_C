#include <stdio.h>
#include <conio.h>

int Sreshta(int chislo, int cifra);

int main()
{
    int chislo, cifra;
    printf("Vuvedete chislo: ");
    scanf("%d", &chislo);
    //getchar();
    printf("\n Vuvedete cifra: ");
    //getche();
    scanf("%d", &cifra);
    printf("\n %d", Sreshta(chislo, cifra));
    return 0;
}

int Sreshta(int chislo, int cifra)
{
    for (chislo; chislo > 0; chislo /= 10)
    {
        if (chislo % 10 == cifra)
        {
            return 1;
        }
    }
    return 0;
}