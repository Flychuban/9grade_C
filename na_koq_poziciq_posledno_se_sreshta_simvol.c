#include <stdio.h>
#include <string.h>

void main()
{
    char s[100], *p;
    int n, j, i, found;
    printf("\n Vuvedete niz i shte se izvede vseki simvol na koe mqsto posledno se sreshta: ");
    fgets(s, 99, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';
    n = strlen(s);
    for (i = n - 1; i >= 0; i--)
    {
        found = 0;
        for (j = n; j > i; j--)
        {
            if (s[i] == s[j])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("\n %c=%d", s[i], i);
        }
    }
}