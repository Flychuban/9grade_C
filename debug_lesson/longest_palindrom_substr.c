#include <stdio.h>

char *longestPalindrome(char *s);

int main(void)
{
    char input[10] = "babcfcbad";
    char *result = longestPalindrome(input);
    printf("%s\n", result);
    return 0;
}

char *longestPalindrome(char *s)
{

    int len = 0;
    while (s[len++])
        ;

    int resultstartindex = 0;
    int max = 1;

    for (int startindex = 0; len - startindex > max; startindex++)
    {
        for (int lastindex = len - 2; lastindex - startindex + 1 > max; lastindex--)
        {
            int ispolyndrome = 1;
            printf("%d ", ispolyndrome);
            int checkstartindex = startindex;
            int checklastindex = lastindex;
            while (checkstartindex <= checklastindex)
            {
                if (s[checkstartindex] != s[checklastindex])
                {
                    ispolyndrome = 0;
                    break;
                }
                checkstartindex++;
                checklastindex--;
            }
            if (ispolyndrome)
            {
                resultstartindex = startindex;
                max = lastindex - resultstartindex + 1;
            }
        }
    }

    for (int i = 0; i < max; i++)
    {
        s[i] = s[i + resultstartindex];
    }
    s[max] = '\0';
    return s;
}