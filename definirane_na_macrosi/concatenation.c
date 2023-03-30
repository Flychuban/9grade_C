#include <stdio.h>

#define CALL_COMMAND(COMMAND) COMMAND ## _command()

void print_command(){
    printf("Printing to the console... \n");
}

void quit_command(){
    printf("The program is quitting");
}

int main(){
    CALL_COMMAND(print);
    CALL_COMMAND(quit);
    return 0;
}