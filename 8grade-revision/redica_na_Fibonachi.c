#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fibr(int n);
void myfib(int n);
void fibsum(int n);

void main()
{
    int choose;
    int n;
    do
    {
        printf("\n 1. Redica na Fibonachi s rekursiq");
        printf("\n 2. Redica na Fibonachi bez rekursiq");
        printf("\n 3. Sumata na chislata na Fibonachi do N");
        printf("\n 4. Exit");
        printf("\n Choose: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            do
            {
                printf("\n n=? (n>=0): ");
                scanf("%d", &n);
            } while (n < 0);
            printf("\n Chisloto na Fibonachi e: %d", fibr(n));
            break;
        case 2:
            myfib(n);
            break;
        case 3:
            fibsum(n);
            break;
        case 4:
            printf("\n Exit.");
            break;
        default:
            printf("\n Incorrect choice!");
        }
    } while (choose != 4);
}

int fibr(int n)
{
    if (n <= 1)
        return n;
    else
    {
        return fibr(n - 1) + fibr(n - 2);
    }
}

void myfib(int n)
{
    int p, a = 0, b = 1, i;
    do
    {
        printf("\n n=? (n>=0): ");
        scanf("%d", &n);
    } while (n < 0);
    if (n <= 1)
        printf("\n Chisloto na Fibonachi e: %d", n);
    else
    {
        for (i = 1; i <= n; i++)
        {
            p = a + b;
            b = a;
            a = p;
        }
        printf("\n Chisloto na fibonachi e: %d", p);
    }
}

void fibsum(int n)
{
    int p, a = 0, b = 1, i, sum = 0;
    do
    {
        printf("\n n=? (n>=0): ");
        scanf("%d", &n);
    } while (n < 0);
    if (n <= 1)
        printf("\n Sumata na chislata na Fibonachi do N e: %d", n);
    else
    {
        for (i = 1; i <= n; i++)
        {
            p = a + b;
            b = a;
            a = p;
            sum = sum + p;
        }
        printf("\n Sumata na chislata na Fibonachi do N e: %d", sum);
    }
}