#include <stdio.h>
#include "transformation.h"

int main(){
    char my_str[100] = "-1456";
    transformation str_to_int = strToInt(my_str);
    printf("%ld \n", str_to_int.result);
    printf("%s", str_to_int.error);
    return 0;
}