#include "hierarchy.h"
#include <stdio.h>
#include <stdlib.h>

static struct ListNode *createnode(struct ProccessInfo proccess_info)
{
    struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->proccess_info = proccess_info;
    return newnode;
}

LinkedList init()
{
    LinkedList list = {size : 0, head : NULL};
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 1 || index + 1 > list->size)
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

void push(LinkedList *list, struct ProccessInfo proccess_info, int index)
{
    if (index == 1)
    {
        pushfront(list, proccess_info);
        printf("\nSize in push if:%d", list->size);
    }
    else if(index > list -> size){
        printf("\nin else if");
        printf("\n%d", list->size);
        struct ListNode *prev = get(list, list->size);
        struct ListNode *newnode = createnode(proccess_info);
        printf("\nHere");
        newnode->next = prev->next;
        prev->next = newnode;
        list->size = list->size + 1;
    }
    else{
        printf("\nelse");
        printf("\nsize in else:%d", list -> size);
        struct ListNode *prev = get(list, index - 1);
        struct ListNode *newnode = createnode(proccess_info);
        newnode->next = prev->next;
        prev->next = newnode;
        list->size = list->size + 1;
    }
}

void pushfront(LinkedList *list, struct ProccessInfo proccess_info)
{
    struct ListNode *newnode = createnode(proccess_info);
    newnode->next = list->head;
    list->head = newnode;
    list->size = list->size + 1;
    printf("\nSize in pushfront:%d", list->size);
}

void pop(LinkedList *list, int index){
    if (index == 1)
    {
        return popfront(list);
    }
    else if(index > list -> size){
        index = list -> size;
    }

    struct ListNode *prev = get(list, index - 1);
    struct ListNode *nodetodelete = prev->next;
    prev->next = nodetodelete->next;
    list->size--;
    free(nodetodelete);
}
void popfront(LinkedList *list){
    struct ListNode *nodetodelete = list->head;
    list->head = list->head->next;
    list->size--;
    free(nodetodelete);
}

void setStatus(LinkedList *list, struct ProccessInfo proccess_info, enum Status new_status, int index)
{
    struct ListNode *node = get(list, index);
    node->proccess_info.status = new_status;
}