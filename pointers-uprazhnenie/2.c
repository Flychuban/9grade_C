#include <stdio.h>
#include <string.h>

int main(){
    char mystr[100];
    printf("Write some text: ");
    fgets(mystr, 100, stdin);
    char *p;
    if(p=strchr(mystr, '\n'))
        *p = '\0';
    
    printf("\n%s", mystr);
    return 0;
}