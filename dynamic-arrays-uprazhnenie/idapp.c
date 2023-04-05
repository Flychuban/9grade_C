#include "dynarr.h"
#include <stdio.h>


void print_all_people(DynamicArray *arr)
{
    printf("\nAll donors: ");
    for (int i = 0; i < arr->size; i++)
    {
        printf("\n%d. Donor: %d", i, getel(arr, i));
    }

    printf("\n");
}

void quit(DynamicArray *arr)
{
    printf("\nExit!");
    releasedynarr(arr);
}

void add_donor(DynamicArray *arr)
{
    int new_donor_id;
    printf("\nEnter new donor ID: ");
    scanf("%d", &new_donor_id);
    pushback(arr, new_donor_id);
}

void remove_donor(DynamicArray *arr)
{
    int id_remove;
    printf("\nEnter donor ID to remove: ");
    scanf("%d", &id_remove);
    remove_person(arr, id_remove);
}

int main(){
    DynamicArray arr_app = init(3);
    char finish = 1;
    while (finish)
    {
        char izbor;
        printf("\n1. Add new donor");
        printf("\n2. Remove donor");
        printf("\n3. Print all donors");
        printf("\n4. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);

        switch (izbor)
        {
        case 1:
            add_donor(&arr_app);
            break;
        case 2:
            remove_donor(&arr_app);
            break;
        case 3:
            print_all_people(&arr_app);
            break;
        case 4:
            quit(&arr_app);
            finish = 0;
            break;
        default:
            printf("\nInvalid option!");
            break;
        }
    }
}