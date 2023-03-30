#include <stdio.h>

int isPowerOfTwo(int n);

int main()
{
    int chislo, result;
    printf("\n Number: ");
    scanf("%d", &chislo);
    result = isPowerOfTwo(chislo);
    if (result == 1)
        printf("\n Chisloto e stepen na dvoikata!");
    else
        printf("\n Chislota NE e stepen na dvoikata!");
    return 0;
}

int isPowerOfTwo(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return isPowerOfTwo(n / 2);
    }
    return 0;
    /* while (1)
     {
         if (n == 1)
         {
             return 1;
         }
         if (n % 2 == 0)
         {
             n /= 2;
         }
         else
             return 0;
     }
     */
}
