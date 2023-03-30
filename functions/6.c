#include <stdio.h>
#include <string.h>
#define maxbr 100

int Compare(char str1[], char str2[]);

int main()
{
    char str1[maxbr], str2[maxbr], *p;
    printf("\n Vuvedete niz: ");
    fgets(str1, maxbr - 1, stdin);
    if (p = strchr(str1, '\n'))
        *p = '\0';
    printf("\n Vuvedete niz: ");
    fgets(str2, maxbr - 1, stdin);
    if (p = strchr(str2, '\n'))
        *p = '\0';
    printf("\n %d", Compare(str1, str2));
    return 0;
}

int Compare(char str1[], char str2[])
{
   // int n;
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    /*  if (n1 > n2)
      {
          n = n1;
      }
      else
          n = n2;
      */
    for (int i = 0; i < n1 || i < n2; i++)
    {
        if (str2[i] < str1[i])
            return 1;
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    return 0;
    // return strcmp(str1, str2);
}