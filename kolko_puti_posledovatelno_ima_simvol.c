#include <stdio.h>
#include <string.h>

void main()
{
    char s[100], *p;
    int n, i, broqch = 1, max;
    printf("\n Vuvedete niz, za da se prebroi broq na ednakvite posledovatelni elementa: ");
    fgets(s, 99, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            broqch++;
            if (broqch > max)
            {
                max = broqch;
            }
        }
        else
        {
            broqch = 1;
        }
    }
    printf("\n MAX ednakvi simvoli e: %d", max);
}