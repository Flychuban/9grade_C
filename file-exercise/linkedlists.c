#include "linkedlists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct BookInfo *createnode(struct BookInfo book)
{
    struct BookInfo *newnode = (struct BookInfo *)malloc(sizeof(struct BookInfo));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    strcpy(newnode->title, book.title);
    strcpy(newnode->author, book.author);
    strcpy(newnode->esbn_number, book.esbn_number);
    strcpy(newnode->genre, book.genre);
    newnode->year_published = book.year_published;
    return newnode;
}

struct BookInfo *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    struct BookInfo *currentnode = list->head;
    for (int i = 0; i < index; i++)
    {
        currentnode = currentnode->next;
    }

    return currentnode;
}


LinkedList init()
{
    LinkedList list = {size : 0, head : NULL};
    return list;
}

void push(LinkedList *list, struct BookInfo book, int index)
{
    if (index == 0)
    {
        pushfront(list, book);
        return;
    }

    struct BookInfo *prev = get(list, index - 1);
    struct BookInfo *newnode = createnode(book);
    newnode->next = prev->next;
    prev->next = newnode;
    list->size++;
}

void pop(LinkedList *list, char esbn_number[10])
{
    struct BookInfo *current_node = list->head;
    while (current_node != NULL)
    {
        if (strcmp(current_node->next->esbn_number, esbn_number) == 0)
        {
            struct BookInfo *prev = current_node;
            struct BookInfo *nodetodelete = prev->next;
            prev->next = nodetodelete->next;
            list->size--;
            free(nodetodelete);
            break;
        }
        current_node = current_node->next;
    }
}

void pushfront(LinkedList *list, struct BookInfo book)
{
    struct BookInfo *newnode = createnode(book);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

