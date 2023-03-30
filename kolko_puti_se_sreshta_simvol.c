#include <stdio.h>
#include <string.h>

void main()
{
    char s[100], *p, c;
    int n, i, broqch = 1, j, sorted;
    printf("\n Vuvedete niz, za da se pokazhe kolko puti se sreshta vseki simvol: ");
    fgets(s, 99, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        sorted = 0;
        for (j = 0; j < n - 1; j++)
        {
            if (s[j + 1] > s[j])
            {
                c = s[j];
                s[j] = s[j + 1];
                s[j + 1] = c;
                sorted = 1;
            }
        }
        if (sorted == 0)
            break;
    }

    for (i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            broqch++;
        }
        else
        {
            printf("\n %c=%d", s[i], broqch);
            broqch = 1;
        }
    }
}
