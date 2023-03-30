#include <stdio.h>
#include <string.h>

char biggestAsciiCode(char str[]);

int main(){
    char str[50];
    printf("Write text?: ");
    fgets(str, 49, stdin);
    int *p;
    if(p = strchr(str, '\n'))
        *p = '\0';
    char biggest_symbol = biggestAsciiCode(str);
    printf("Symbol with biggest ASCII code: %c", biggest_symbol);
    return 0;
}

char biggestAsciiCode(char str[]){
    char biggest_symbol;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(i == 0){
            biggest_symbol = str[i];
        }
        else if(str[i] > biggest_symbol){
            biggest_symbol = str[i];
        } 
    }
    return biggest_symbol;
}