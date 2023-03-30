#include <stdio.h>
#include <string.h>

int main()
{
    char s[100], *p;
    int i, n, lengt, max = 1, j, ok, index = 0;
    printf("\n Vuvedete niz: ");
    fgets(s, 99, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';
    n = strlen(s);
    for (i = 1; i < n; i++)
    {
        lengt = 1;
        ok = 1;
        for (j = index; j < i; j++)
        {
            if (s[i] != s[j])
            {
                lengt++;
            }
            else
            {
                ok = 0;
                index = j + 1;
                break;
            }
        }
        if (ok && lengt > max)
            max = lengt;
    }
    printf("\n Dulzhinata na nepovtarqshtite se simvoli e: %d", max);
    return 0;
}