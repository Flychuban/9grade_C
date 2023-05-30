#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlists.h"

void save_file_changes(LinkedList *list, FILE *textFile){

}


void print_all_activities(LinkedList *list)
{
    struct PersonInfo *current_node = list->head;
    while (current_node != NULL)
    {
        printf("\n");
        printf("Year published: %d", current_node->year_published);
        printf("\n");
        printf("Title: %s\n", current_node->title);
        printf("Author name: %s\n", current_node->author);
        printf("person genre: %s\n", current_node->genre);
        printf("ESBN number: %s\n", current_node->esbn_number);
        current_node = current_node->next;
    }
}

void quit(LinkedList *list)
{
    struct PersonInfo *current_node = list->head;
    FILE *fp = fopen("persons.txt", "w");
    while (current_node != NULL)
    {
        fprintf(fp, "%d\n", current_node->year_published);
        fputs(current_node->title, fp);
        fprintf(fp, "\n");
        fputs(current_node->author, fp);
        fprintf(fp, "\n");
        fputs(current_node->genre, fp);
        fprintf(fp, "\n");
        fputs(current_node->esbn_number, fp);
        fprintf(fp, "\n");
        fprintf(fp, "\n");
        current_node = current_node->next;
    }
    fclose(fp);

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

void add_person(LinkedList *list)
{
    struct PersonInfo new_person;
    char *p;
    getchar();
    printf("\nEnter new person title: ");
    fgets(new_person.title, 100, stdin);
    if (p = strchr(new_person.title, '\n'))
        *p = '\0';

    printf("\nEnter name person author: ");
    fgets(new_person.author, 30, stdin);
    if (p = strchr(new_person.author, '\n'))
        *p = '\0';

    printf("\nEnter person genre: ");
    fgets(new_person.genre, 30, stdin);
    if (p = strchr(new_person.genre, '\n'))
        *p = '\0';

    printf("\nEnter person ISBN number: ");
    fgets(new_person.esbn_number, 10, stdin);
    if (p = strchr(new_person.esbn_number, '\n'))
        *p = '\0';

    printf("\nEnter year person published: ");
    scanf("%d", &new_person.year_published);
    push(list, new_person, list->size);
}

void remove_person(LinkedList *list)
{
    char esbn_number[10];
    char *p;
    getchar();
    printf("\nEnter ESBN number to remove: ");
    fgets(esbn_number, 10, stdin);
    if (p = strchr(esbn_number, '\n'))
        *p = '\0';
    pop(list, esbn_number);
    printf("\nRemoved person!");
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
        printf("Cannot open file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(textFile, "%d", &person.year_published) != EOF)
    {
        fscanf(textFile, "\n");
        fgets(person.title, 100, textFile);
        if (p = strchr(person.title, '\n'))
            *p = '\0';
        fscanf(textFile, "\n");
        fgets(person.author, 30, textFile);
        if (p = strchr(person.author, '\n'))
            *p = '\0';
        fscanf(textFile, "\n");
        fgets(person.genre, 30, textFile);
        if (p = strchr(person.genre, '\n'))
            *p = '\0';
        fscanf(textFile, "\n");
        fgets(person.esbn_number, 10, textFile);
        if (p = strchr(person.esbn_number, '\n'))
            *p = '\0';
        fscanf(textFile, "\n");
        push(&list, person, i);
        i++;
    }

    fclose(textFile);

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
            add_person(&list);
            break;
        case 2:
            remove_person(&list);
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