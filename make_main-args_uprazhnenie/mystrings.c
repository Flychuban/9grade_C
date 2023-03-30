#include "mystrings.h"
#include <string.h>
#include <stdio.h>
int strlength(char *my_string){
    int length = 0;
    int broqch = 0;
    while (my_string[broqch] != '\0'){
        broqch++;
        length++;
    }
    return length;
}

void strconcat(char *my_string1, char *my_string2, int len1, int len2){    
    for (int i = 0; i < len2; i++){
        printf("%c ", my_string2[i]);
        my_string1[len1 + i] = my_string2[i];
    } 
}

int strcompare(char *my_string1, char *my_string2){
    int len1 = strlength(my_string1);
    int len2 = strlength(my_string2);
    int length;
    if (len1 > len2){
        length = len1;
    }
    else{
        length = len2;
    }
    for (int i = 0; i < length; i++){
        if (my_string1[i] < my_string2[i]){
            return -1;
        }
        else if(my_string1[i] > my_string2[i]){
            return 1;
        }
    }
    return 0;
}