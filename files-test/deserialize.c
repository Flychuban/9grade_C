#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donation.h"

#define LINE_MAX_LENGTH 1024

struct ListNode
{
    struct Donation value;
    struct ListNode *next;
};

typedef struct
{
    int size;
    struct ListNode *head;
} LinkedList;

static struct ListNode *createnode(struct Donation value)
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

void pushfront(LinkedList *list, struct Donation value)
{
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

void push(LinkedList *list, int index, struct Donation value)
{
    if (index == 0)
    {
        pushfront(list, value);
    }
    else
    {
        struct ListNode *prevnode = get(list, index - 1);
        struct ListNode *newnode = createnode(value);
        newnode->next = prevnode->next;
        prevnode->next = newnode;
        list->size++;
    }
}

void pushback(LinkedList *list, struct Donation value)
{
    push(list, list->size, value);
}

struct Donation popfront(LinkedList *list)
{
    struct ListNode *nodetodelete = list->head;
    list->head = nodetodelete->next;
    list->size--;

    struct Donation result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

struct Donation pop(LinkedList *list, int index)
{
    if (index == 0)
    {
        return popfront(list);
    }

    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *nodetodelete = prevnode->next;
    prevnode->next = nodetodelete->next;
    list->size--;

    struct Donation result = nodetodelete->value;
    free(nodetodelete);
    return result;
}
struct Donation popback(LinkedList *list)
{
    return pop(list, list->size - 1);
}

int main(){
    FILE *inputFile = fopen("charityList.csv", "r");

    if (inputFile == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    LinkedList all_donors = init();

    char line[LINE_MAX_LENGTH];

    struct Donation each_donor;
    while (fgets(line, LINE_MAX_LENGTH, inputFile) != NULL)
    {
        char *newline = strchr(line, '\n');
        if (newline != NULL)
        {
            *newline = '\0';
        }

        char *donor = strtok(line, ",");
        strcpy(each_donor.donor, donor);

        char *cause = strtok(NULL, ",");
        strcpy(each_donor.cause, cause);

        char *amount = strtok(NULL, ",");
        each_donor.amount = atoi(amount);

        pushback(&all_donors, each_donor);
    }

    for (int i = 0; i < all_donors.size; i++)
    {
        struct Donation each_donor = get(&all_donors, i)->value;
        printf("Donor: %s, Cause: %s, Amount: %d\n", each_donor.donor, each_donor.cause, each_donor.amount);
    }

    fclose(inputFile);
    return 0;
}