#include <stdio.h>
#include <string.h>

int strLength(char str[]);

int main()
{
    int result;
    char *p;
    char str[100];
    printf("Vuvedete niz: ");
    fgets(str, 99, stdin);
    if (p = strchr(str, '\n'))
        *p = '\0';
    printf("\n Length: %d", strLength(str));
    return 0;
}

int strLength(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;  
    return i;
}