#include <stdio.h>
#include <string.h>
#define maxbr 100

int strLength(char str[]);
int Prosto(int chislo);
int Sreshta(int chislo, int cifra);
void proverka(int arr[], int arrSize);
void Gluing(char str1[], char str2[]);
int Compare(char str1[], char str2[]);

int main()
{
    int izbor;
    int result;
    char *p;
    char str[100];
    int chislo;
    int cifra;
    int arr[100], n;
    char str1[100], str2[50];

    do
    {
        printf("\n");
        printf("\n1. String length");
        printf("\n2. Dali chislo e prosto");
        printf("\n3. Dali cifra se sreshta");
        printf("\n4. Dali chislo e prosto i dali v nego se sreshta cifra");
        printf("\n5. Zalepvane na dva stringa");
        printf("\n6. String Compare");
        printf("\n7. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);
        getchar();

        switch (izbor)
        {
        case 1:
            printf("Vuvedete niz: ");
            fgets(str, 99, stdin);
            if (p = strchr(str, '\n'))
                *p = '\0';
            printf("\n Length: %d", strLength(str));

            break;
        case 2:
            printf("\n Chislo: ");
            scanf("%d", &chislo);
            printf("\n %d", Prosto(chislo));

            break;
        case 3:
            printf("Vuvedete chislo: ");
            scanf("%d", &chislo);
            // getchar();
            printf("\n Vuvedete cifra: ");
            // getche();
            scanf("%d", &cifra);
            printf("\n %d", Sreshta(chislo, cifra));

            break;
        case 4:
            printf("\n Vuvedete broq na elementite: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("\n Chislo[%d]= ", i + 1);
                scanf("%d", &arr[i]);
            }
            proverka(arr, n);

            break;
        case 5:
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

            break;
        case 6:
            printf("\n Vuvedete niz: ");
            fgets(str1, 100 - 1, stdin);
            if (p = strchr(str1, '\n'))
                *p = '\0';
            printf("\n Vuvedete niz: ");
            fgets(str2, 100 - 1, stdin);
            if (p = strchr(str2, '\n'))
                *p = '\0';
            result = Compare(str1, str2);
            if (result == 0)
            {
                printf("\n Strings are similar");
            }
            else if (result < 0)
            {
                printf("\n First string is before other");
            }
            else
            {
                printf("\n Second string is before other ");
            }

            break;
        case 7:
            printf("\n Exit!");
            break;
        default:
            printf("\n Choose again");
            break;
        }
    } while (izbor != 7);

    return 0;
}

int strLength(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

int Prosto(int chislo)
{
    for (int i = 2; i < chislo / 2; i++)
    {
        if (chislo % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Sreshta(int chislo, int cifra)
{
    for (chislo; chislo > 0; chislo /= 10)
    {
        if (chislo % 10 == cifra)
        {
            return 1;
        }
    }
    return 0;
}

void proverka(int arr[], int arrSize)
{
    int cifra;
    printf("\n Vuvedete cifra koqto da se potursi dali se sreshta: ");
    scanf("%d", &cifra);
    for (int i = 0; i < arrSize; i++)
    {
        if (Prosto(arr[i]) && Sreshta(arr[i], cifra))
        {
            printf("%d ", arr[i]);
        }
    }
}

void Gluing(char str1[], char str2[])
{
    int i;
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    for (i = 0; i < n2 + 1; i++)
    {
        str1[n1 + i] = str2[i];
    }
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