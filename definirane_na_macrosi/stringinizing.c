#include <stdio.h>

#define DEBUG(VALUE, FORMAT) printf("The value is:" FORMAT "\n", VALUE)
#define DEBUG_NAME(VALUE, FORMAT) printf("The value of " #VALUE " is:" FORMAT "\n", VALUE)

int main(){
    printf("HEllo, " "world\n");

    int somevar = 7;
    DEBUG(somevar, "%d");
    DEBUG_NAME(somevar, "%d");
    return 0;
}