#include <stdio.h>

int main(){
    int n, izbor;
    int on_rooms = 0;
    while(1){
        printf("1.Switch lights \n");
        printf("2.Print State \n");
        printf("3.Quit \n");
        printf("Choose: ");
        scanf("%d", &izbor);
        if (izbor == 3)
        {
            break;
        }
        else if (izbor == 1)
        {
            printf("\nNumber room:");
            scanf("%d", &n);
            if (n>0 && n<9){
                on_rooms = on_rooms ^ 1 << (n - 1); // switch lamp in room N
            }
        }
        else if(izbor == 2){
            printf("\nLights turn ON: ", on_rooms);
            for (int i = 1; i <= 8; i++){
                int new_room = 1 << (i - 1);
                if ((on_rooms & new_room) == new_room) // checks whether room N is ON 
                {
                    printf(" %d", i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}