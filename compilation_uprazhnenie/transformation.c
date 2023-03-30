#include <stdio.h>
#include <string.h>
#include "transformation.h"

transformation strToInt(char *my_str){
    transformation tr;
    int number_started = 0; //tova proverqva za '-' ako e v nachaloto
    int number_int = 0;
    int minus_flag = 0;
    int flag_error = 0;
    for (int i = 0; i < strlen(my_str); i++){
        char symbol = my_str[i];
        if(!number_started){
            if (symbol == '-'){
                minus_flag = 1;
                number_started = 1;
            }
            else if (symbol>= '0' && symbol<='9'){
                number_int = number_int * 10 + (symbol-48); // -48 ascii table char -> int
                number_started = 1;
                printf("%d \n", number_int);
            }
            else{
                flag_error = 1;
                break;
            }   
        }
        else{
            if (symbol >= '0' && symbol <= '9'){
                number_int = number_int * 10 + (symbol-48);
                printf("%d \n", number_int);
            }
            else{
                flag_error = 1;
                break;
            }
        }
    }

    if (flag_error){
        tr.result = 0;
        strcpy(tr.error, "Invalid input string");
    }
    else{
        if (minus_flag){
            number_int = number_int * (-1);
        }

        tr.result = number_int;
        strcpy(tr.error, "\0");
    }
    
    return tr;
}