#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlists.h"

void save_file_changes(LinkedList *list, char *fileName){
    FILE *textFile = fopen(fileName, "wb");
    if (textFile == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    fwrite(&list->size, sizeof(int), 1, textFile);
    for (int i = 0; i < list->size; i++)
    {
        fwrite(get(list, i), sizeof(struct PersonInfo), 1, textFile);
    }
    fclose(textFile);
}


void print_all_activities(LinkedList *list)
{
    struct PersonInfo *current_node = list->head;
    while (current_node != NULL)
    {
        printf("--------------------\n");
        printf("ID: %d\n", current_node->ID);
        printf("Name: %s\n", current_node->name);
        printf("Age: %d\n", current_node->age);
        printf("Education: ");
        switch (current_node->education)
        {
        case 0:
            printf("NOEDUCATION\n");
            break;
        case 1:
            printf("PRIMARY\n");
            break;
        case 2:
            printf("SECONDARY\n");
            break;
        case 3:
            printf("MASTER\n");
            break;
        default:
            printf("Invalid education!\n");
            break;
        }

        printf("Family type: ");
        switch (current_node->family)
        {
        case 0:
            printf("SINGLE\n");
            break;
        case 1:
            printf("MARRIED\n");
            break;
        default:
            printf("Invalid family type!\n");
            break;
        }

        printf("Work status: ");
        switch (current_node->work)
        {   
        case 0:
            printf("UNEMPLOYED\n");
            break;
        case 1:
            printf("WORKING\n");
            break;
        default:
            printf("Invalid work status!\n");
            break;
        }
        printf("--------------------\n");
        current_node = current_node->next;
    }
}

void quit(LinkedList *list)
{
    struct PersonInfo *current_node = list->head;
    if (list->head != NULL)
    {
        current_node = list->head;
        while (current_node != NULL)
        {
            struct PersonInfo *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
    list->head = NULL;
    list->size = 0;
    printf("\nExit!");
}

void add_person(LinkedList *list, char *fileName)
{
    struct PersonInfo new_person;
    char *p;
    getchar();

    printf("\nEnter new person ID: ");
    scanf("%d", &new_person.ID);

    getchar();
    printf("\nEnter new person name: ");
    fgets(new_person.name, 255, stdin);
    if (p = strchr(new_person.name, '\n'))
        *p = '\0';
    
    printf("\nEnter new person age: ");
    scanf("%d", &new_person.age);

    printf("\nNew person education: (0)-NOEDUCATION, (1)-PRIMARY, (2)-SECONDARY, (3)-MASTER\n");
    printf("\nEnter new person education number: ");
    scanf("%d", &new_person.education);
    
    printf("\nEnter new person family type: (0)-SINGLE, (1)-MARRIED\n");
    printf("\nEnter new person family type number: ");
    scanf("%d", &new_person.family);
    
    printf("\nEnter new person work status: (0)-UNEMPLOYED, (1)-WORKING\n");
    printf("\nEnter new person work status number: ");
    scanf("%d", &new_person.work);

    push(list, new_person, list->size);
    printf("\nSuccessfully added new person!");
    save_file_changes(list, fileName);
}

void remove_person(LinkedList *list, char *fileName)
{
    int ID_to_remove;
    char *p;
    getchar();
    printf("\nEnter ID number to remove: ");
    scanf("%d", &ID_to_remove);
    pop(list, ID_to_remove);
    printf("\nSuccessfully removed person!");

    save_file_changes(list, fileName);
}

int main()
{
    LinkedList list = init();
    struct PersonInfo person;

    char fileName[100], *p;
    printf("Enter file name: ");
    fgets(fileName, 100, stdin);

    if (p = strchr(fileName, '\n'))
        *p = '\0';

    FILE *textFile = fopen(fileName, "rb");

    if (textFile == NULL)
    {
        printf("File is empty!\n");
    }

    else{
        printf("File is not empty and it's successfully opened!\n");
        int person_count;

        fread(&person_count, sizeof(int), 1, textFile);

        for(int i = 0; i < person_count; i++){
            struct PersonInfo new_person;
            fread(&new_person, sizeof(struct PersonInfo), 1, textFile);
            push(&list, new_person, list.size);
        }

        fclose(textFile);
    }

    char finish = 1;
    while (finish)
    {
        char izbor;
        printf("\n1. Add new person");
        printf("\n2. Remove person");
        printf("\n3. Print file data");
        printf("\n4. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);

        switch (izbor)
        {
        case 1:
            add_person(&list, fileName);
            break;
        case 2:
            remove_person(&list, fileName);
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

    return 0;
}