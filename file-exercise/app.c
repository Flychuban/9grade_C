#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlists.h"

void print_all_activities(LinkedList *list)
{
    struct BookInfo *current_node = list->head;
    while (current_node != NULL)
    {
        printf("\n");
        printf("Year published: %d\n", current_node->year_published);
        printf("Title: %s\n", current_node->title);
        printf("Author name: %s\n", current_node->author);
        printf("Book genre: %s\n", current_node->genre);
        printf("ESBN number: %s\n", current_node->esbn_number);
        current_node = current_node->next;
    }
}

void quit(LinkedList *list, FILE *fp)
{
    struct BookInfo *current_node = list->head;
    while (current_node != NULL)
    {
        fprintf(fp, "%d\n", current_node->year_published);
        fputs(current_node->title, fp);
        fputs(current_node->author, fp);
        fputs(current_node->genre, fp);
        fputs(current_node->esbn_number, fp);
        current_node = current_node->next;
    }
    fclose(fp);

    if (list->head != NULL)
    {
        struct BookInfo *current_node = list->head;
        while (current_node != NULL)
        {
            struct BookInfo *next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }
    list->head = NULL;
    list->size = 0;
    printf("\nExit!");
}

void add_book(LinkedList *list)
{
    struct BookInfo new_book;
    char *p;
    int index = 0;
    getchar();
    printf("\nEnter new book title: ");
    fgets(new_book.title, 100, stdin);
    if (p = strchr(new_book.title, '\n'))
        *p = '\0';

    printf("\nEnter name book author: ");
    fgets(new_book.author, 30, stdin);
    if (p = strchr(new_book.author, '\n'))
        *p = '\0';

    printf("\nEnter book genre: ");
    fgets(new_book.genre, 30, stdin);
    if (p = strchr(new_book.genre, '\n'))
        *p = '\0';

    printf("\nEnter year book published: ");
    scanf("%d", new_book.year_published);
    push(list, new_book, index);
    index++;
}

void remove_book(LinkedList *list)
{
    char esbn_number[10];
    printf("\nEnter ESBN number to remove: ");
    fgets(esbn_number, 10, stdin);
    pop(list, esbn_number);
    printf("\nRemoved book!");
}

int main()
{
    LinkedList list = init();
    struct BookInfo book;
    FILE *textFile = fopen("books.txt", "w+");

    if (textFile == NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }

    while (fscanf(textFile, "%d\n", book.year_published) != EOF)
    {
        fgets(book.title, 100, textFile);
        fgets(book.author, 30, textFile);
        fgets(book.genre, 30, textFile);
        fgets(book.esbn_number, 10, textFile);   
    }
    

    char finish = 1;
    while (finish)
    {
        char izbor;
        printf("\n1. Add new book");
        printf("\n2. Remove book");
        printf("\n3. Print all books");
        printf("\n4. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);

        switch (izbor)
        {
        case 1:
            add_book(&list);
            break;
        case 2:
            remove_book(&list);
            break;
        case 3:
            print_all_activities(&list);
            break;
        case 4:
            quit(&list, textFile);
            finish = 0;
            break;
        default:
            printf("\nInvalid option!");
            break;
        }
    }

    return 0;
}