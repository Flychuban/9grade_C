#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    double value;
};

struct LinkedList
{
    struct Node *head;
    int size;
};

struct Stack
{
    struct LinkedList list;
};

static struct Node *createnode(double value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    return newnode;
}

struct LinkedList init()
{
    struct LinkedList list = {size : 0, head : NULL};
    return list;
}

struct Stack stack_init()
{
    struct LinkedList linked_list = init();
    struct Stack stack = {list : linked_list};
}

struct Node *get(struct LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }
}

void pushfront(struct LinkedList *list, double value)
{
    struct Node *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

void popfront(struct LinkedList *list)
{
    struct Node *nodetodelete = list->head;
    list->head = list->head->next;
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);
}

void push(struct Stack *stack, double value)
{
    pushfront(&stack->list, value);
}

void pop(struct Stack *stack)
{
    popfront(&stack->list);
}

void printlinkedlist(struct Stack *stack)
{
    struct Node *currentnode = stack->list.head;
    while (currentnode != NULL)
    {
        printf("%lf ", currentnode->value);
        currentnode = currentnode->next;
    }
    printf("\n");
}

int main()
{
    struct Stack stack = stack_init();
    push(&stack, 24.69);
    push(&stack, 8);
    push(&stack, 15);

    printlinkedlist(&stack);
    return 0;
}