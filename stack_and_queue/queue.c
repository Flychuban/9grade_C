#include <stdio.h>
#include <stdlib.h>

//  Queue implementation using double linked list

struct Node{
    struct Node *next;
    struct Node *prev;
    double value;
};

struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int size;
};

struct Queue{
    struct LinkedList list;
};

struct LinkedList init(){
    struct LinkedList list = {size : 0, head : NULL, tail : NULL};
    return list;
}

struct Queue queue_init(){
    struct LinkedList linked_list = init();
    struct Queue queue = {list : linked_list};
    return queue;
}

struct Node *createnode(double value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL){
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    return newnode;
}

struct Node *get(struct LinkedList *list, int index){
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }
    if (index <= list->size / 2)
    {
        struct ListNode *currentnode = list->head;
        for (int i = 0; i < index; i++)
        {
            currentnode = currentnode->next;
        }
        return currentnode;
    }
    else
    {
        struct ListNode *currentnode = list->tail;
        for (int i = list->size - 1; i > index; i--)
        {
            currentnode = currentnode->prev;
        }
        return currentnode;
    }
}

int main(){
    struct Queue queue = queue_init();
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    
    return 0;
}