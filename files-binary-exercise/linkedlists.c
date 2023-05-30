#include "linkedlists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct PersonInfo *createnode(struct PersonInfo person)
{
    struct PersonInfo *newnode = (struct PersonInfo *)malloc(sizeof(struct PersonInfo));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->ID = person.ID;
    newnode->age = person.age;
    strcpy(newnode->name, person.name);
    newnode->education = person.education;
    newnode->family = person.family;
    newnode->work = person.work;

    return newnode;
}

struct PersonInfo *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    struct PersonInfo *currentnode = list->head;
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

void push(LinkedList *list, struct PersonInfo person, int index)
{
    if (index == 0)
    {
        pushfront(list, person);
        return;
    }

    struct PersonInfo *prev = get(list, index - 1);
    struct PersonInfo *newnode = createnode(person);
    newnode->next = prev->next;
    prev->next = newnode;
    list->size++;
}

void pop(LinkedList *list, int ID)
{
    struct PersonInfo *current_node = list->head;
    while (current_node != NULL)
    {
        if (current_node->next->ID == ID)
        {
            struct PersonInfo *prev = current_node;
            struct PersonInfo *nodetodelete = prev->next;
            prev->next = nodetodelete->next;
            list->size--;
            free(nodetodelete);
            break;
        }
        current_node = current_node->next;
    }
}

void pushfront(LinkedList *list, struct PersonInfo person)
{
    struct PersonInfo *newnode = createnode(person);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

