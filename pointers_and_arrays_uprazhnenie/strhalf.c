#include <stdio.h>
#include <string.h>

void strhalf(char * mystr, char **pp){
    int str_size = strlen(mystr);
    *pp += str_size / 2;
}

int main(){
    char mystr[] = "asdfghf";
    char *pp = mystr;

    strhalf(mystr, &pp);
    printf("%s", pp);
    
    return 0;
}