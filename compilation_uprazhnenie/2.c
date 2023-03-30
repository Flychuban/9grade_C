#include <stdio.h>

int main(){
    int a = 17;
    int b = 5;
    int broqch;
    if (a>b){
        broqch = a;
    }
    else{
        broqch = b;
    }

    int nok;
    while(1){
        if(broqch % a == 0 && broqch % b == 0){
            nok = broqch;
            break;
        }
        broqch++;
    }

    printf("NOK: %d", nok);
    
    
    return 0;
}