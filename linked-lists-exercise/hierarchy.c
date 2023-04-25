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
    if (index < 1 || index > list->size)
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

void push(LinkedList *list, struct ProccessInfo proccess_info)
{
    if (proccess_info.proccess_number == 1)
    {
        pushfront(list, proccess_info);
    }
    else if(proccess_info.proccess_number > list -> size){
        proccess_info.proccess_number = list -> size + 1;
        struct ListNode *prev = get(list, proccess_info.proccess_number - 1);
        struct ListNode *newnode = createnode(proccess_info);
        newnode->next = prev->next;
        prev->next = newnode;
        list->size++;
    }
    else{
        struct ListNode *prev = get(list, proccess_info.proccess_number - 1);
        struct ListNode *newnode = createnode(proccess_info);
        newnode->next = prev->next;
        prev->next = newnode;
        list->size++;
    }
}

void pushfront(LinkedList *list, struct ProccessInfo proccess_info)
{
    struct ListNode *newnode = createnode(proccess_info);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
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

void setStatus(LinkedList *list, struct ProccessInfo proccess_info, enum Status new_status)
{
    struct ListNode *node = get(list, proccess_info.proccess_number);
    node->proccess_info.status = new_status;
}