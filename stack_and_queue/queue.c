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

void pushback(struct LinkedList *list, double value){
    struct Node *newnode = createnode(value);
    if (list->size == 0){
        list->head = newnode;
        list->tail = newnode;
    }
    else{
        newnode->prev = list->tail;
        list->tail->next = newnode;
        list->tail = newnode;
    }
    list->size++;
}

void popfront(struct LinkedList *list){
    struct Node *newhead = list->head->next;
    free(list->head);
    list->head = newhead;
    list->size--;
}


void enqueue(struct Queue *queue, double value){
    pushback(&queue->list, value);
}

void dequeue(struct Queue *queue){
    popfront(&queue->list);
}

void printQueue(struct Queue *queue){
    struct Node *currentnode = queue->list.head;


    for (int i = 0; i < queue->list.size; i++)
    {
        printf("%lf ", currentnode->value);
        currentnode = currentnode->next;
    }
    
    printf("\n");
}


int main(){
    struct Queue queue = queue_init();
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    
    dequeue(&queue);
    printQueue(&queue);

    return 0;
}