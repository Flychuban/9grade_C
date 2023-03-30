#include <stdio.h>

int Prosto(int chislo);

int main()
{
    int chislo;
    printf("\n Chislo: ");
    scanf("%d", &chislo);
    printf("\n %d", Prosto(chislo));
    return 0;
}


int Prosto(int chislo)
{
    for (int i = 2; i < chislo/2; i++)
    {
        if (chislo % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/*void Prosto(int chislo)
{
    int found=0;
    for (int i = 2; i < chislo/2; i++)
    {
        if (chislo%i==0)
        {
            printf("\n Sustavno chislo e!");
            found=1;
            break;
        }
    }
    if(!found)
        printf("\n Prosto chislo e!");
}
*/