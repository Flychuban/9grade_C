#include <stdio.h>
#include "lists.h"

static struct ListNode *createnode(double value)
{
    struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    return newnode;
}

LinkedList init()
{
    LinkedList list = {size : 0, head : NULL};
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    struct ListNode *currentnode = list->head;
    for (int i = 0; i < index; i++)
    {
        currentnode = currentnode->next;
    }

    return currentnode;
}

void pushfront(LinkedList *list, double value)
{
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

double popfront(LinkedList *list)
{
    struct ListNode *nodetodelete = list->head;
    list->head = list->head->next;
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

void set(LinkedList *list, int index, double value)
{
    struct ListNode *node = get(list, index);
    node->value = value;
}