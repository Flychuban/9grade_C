#include <stdio.h>
#include "hierarchy.h"
#include <string.h>
#include <stdlib.h>

void print_all_activities(LinkedList *list)
{
    struct ListNode *current_node = list->head;
    while (current_node != NULL)
    {
        printf("%d. ", current_node->proccess_info.proccess_number);
        printf("%s ", current_node->proccess_info.proccess_name);
        if (current_node->proccess_info.status == NEW)
        {
            printf("NEW");
        }
        else if (current_node->proccess_info.status == IN_PROGRESS)
        {
            printf("IN_PROGRESS");
        }
        else
        {
            printf("DONE");
        }
        printf("\n");
        current_node = current_node->next;
    }
    printf("\n");
}

void quit(LinkedList *list)
{
    printf("\nExit!");
    // release(list);
}

void add_activity(LinkedList *list)
{
    struct ProccessInfo new_proccess_info;
    char *p;
    printf("\nEnter new activity number: ");
    scanf("%d", &new_proccess_info.proccess_number);
    getchar();
    printf("\nEnter new activity name: ");
    fgets(new_proccess_info.proccess_name, 30, stdin);
    if(p = strchr(new_proccess_info.proccess_name, '\n'))
        *p = '\0';
    new_proccess_info.status = NEW;
    push(list, new_proccess_info);
}

void remove_activity(LinkedList *list)
{
    int remove_proccess_number;
    printf("\nEnter activity number to remove: ");
    scanf("%d", &remove_proccess_number);
    pop(list, remove_proccess_number);
}

int main()
{
    LinkedList list = init();
    char finish = 1;
    while (finish)
    {
        char izbor;
        printf("\n1. Add new activity");
        printf("\n2. Remove activity");
        printf("\n3. Print all activities");
        printf("\n4. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);

        switch (izbor)
        {
        case 1:
            add_activity(&list);
            break;
        case 2:
            remove_activity(&list);
            break;
        case 3:
            print_all_activities(&list);
            break;
        case 4:
            quit(&list);
            finish = 0;
            break;
        default:
            printf("\nInvalid option!");
            break;
        }
    }
}