#include "linkedlist.h"
#include <stdio.h>

void printlinkedlist(LinkedList *list)
{
    struct ListNode *currentnode = list->head;
    while (currentnode != NULL)
    {
        printf("%lf ", currentnode->value);
        currentnode = currentnode->next;
    }
    printf("\n");
}

int main(void)
{
    LinkedList list = init();
    printlinkedlist(&list);

    pushfront(&list, 3);
    pushfront(&list, 7);
    pushfront(&list, 5);
    pushfront(&list, 4);
    printlinkedlist(&list);

    struct ListNode *el3 = get(&list, 2);
    printf("Element 3: %lf \n", el3->value);

    double firstel = popfront(&list);
    printf("First element %lf \n", firstel);
    printlinkedlist(&list);

    set(&list, 2, 17);
    printlinkedlist(&list);

    return 0;
}