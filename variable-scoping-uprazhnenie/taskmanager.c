#include <stdio.h>
#include <string.h>
#include "processes.h"

int main(){
    while (1){
        int izbor;
        printf("1. Create new process\n");
        printf("2. Stop a process\n");
        printf("3. Print all active processes\n");
        printf("4. Quit\n");
        printf("Choose: ");
        scanf("%d", &izbor);

        if (izbor == 1){
            char name[30] ,*p;
            getchar();
            printf("\nEnter the name of new process: ");
            fgets(name, 29, stdin);
            if (p = strchr(name, '\n'))
                *p = '\0';
            printf("\n%s", name);
            createnewprocesses(name);
        }
        else if(izbor == 2){
            unsigned long long stop_id;
            printf("\nEnter the ID for stopping this process: ");
            scanf("%llu", &stop_id);
            stopprocess(stop_id);
        }
        else if(izbor == 3){
            printprocesses();
        }
        else if(izbor == 4){
            return quitprogram();
        }
        printf("\n");
    }    
    return 0;
}
