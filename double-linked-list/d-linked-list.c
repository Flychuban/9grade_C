#include "d-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

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
    LinkedList list = {size : 0, head : NULL, tail : NULL};
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }
    if (index <= list->size/2){
        struct ListNode *currentnode = list->head;
        for (int i = 0; i < index; i++)
        {
            currentnode = currentnode->next;
        }
        return currentnode;
    }
    else{
        struct ListNode *currentnode = list->tail;
        for (int i = list->size-1; i > index; i--)
        {
            currentnode = currentnode->prev;
        }
        return currentnode;
    }

}

void push(LinkedList *list, int index, double value)
{
    if (index == 0)
    {
        pushfront(list, value);
        return;
    }

    struct ListNode *prev_node = get(list, index - 1);
    struct ListNode *newnode = createnode(value);
    newnode->next = prev_node->next;
    newnode->prev = prev_node;
    prev_node->next = newnode;
    newnode->next->prev = newnode;
    list->size++;
}

void pushback(LinkedList *list, double value)
{
    struct ListNode *newnode = createnode(value);
    if (list->size == 0)
    {
        list->head = newnode;
    }
    newnode->prev = list->tail;
    newnode->next = NULL;
    list->tail->next = newnode;
    list->tail = newnode;
    list->size++;
}

void pushfront(LinkedList *list, double value)
{
    struct ListNode *newnode = createnode(value);
    if (list->size == 0)
    {
        list->tail = newnode;
    }
    newnode->next = list->head;
    newnode->prev = NULL;
    list->head = newnode;
    list->head->prev = newnode;
    list->size++;
}

double pop(LinkedList *list, int index)
{
    if (index == 0)
    {
        return popfront(list);
    }

   
    struct ListNode *prev_node = get(list, index - 1);
    struct ListNode *nodetodelete = prev_node->next;
    prev_node->next = nodetodelete->next;
    nodetodelete->next->prev = prev_node;

    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

double popfront(LinkedList *list)
{
    struct ListNode *nodetodelete = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

double popback(LinkedList *list)
{
    struct ListNode *nodetodelete = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
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

void release(LinkedList *list){
    struct ListNode *currentnode = list->head;
    while (currentnode != NULL)
    {
        struct ListNode *nodetodelete = currentnode;
        currentnode = currentnode->next;
        free(nodetodelete);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}