#include <stdio.h>

int main(){
    char mystr[10] = "abcdefgh";

    for(int i = 0; *(mystr + i) != '\0'; i++)
    {
        printf("%c", *(mystr + i));
    }

    return 0;
}