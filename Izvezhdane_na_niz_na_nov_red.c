#include <stdio.h>
#include <string.h>
void main()
{
    int i, n;
    char s[100], *p;
    printf("\n Vuvedete niz: ");
    fgets(s, 99, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';
    n = strlen(s);
    for (i = 0; i <= n; i++)
        printf("\n %c", s[i]);
}