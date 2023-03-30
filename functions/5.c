#include <stdio.h>
#include <string.h>

void Gluing(char str1[], char str2[]);

int main()
{
    char str1[100], str2[50], *p;
    printf("\nVuvedete Niz: ");
    fgets(str1, 49, stdin);
    if (p = strchr(str1, '\n'))
        *p = '\0';
    printf("\nVuvedete niz: ");
    fgets(str2, 49, stdin);
    if (p = strchr(str2, '\n'))
        *p = '\0';
    Gluing(str1, str2);
    printf("\n %s", str1);
    return 0;
}

void Gluing(char str1[], char str2[])
{
    int i;
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    for ( i = 0; i < n2+1; i++)
    {
        str1[n1+i] = str2[i];
    }
}