#ifndef HIERARCHY
#define HIERARCHY

enum Status { 
    NEW, 
    IN_PROGRESS, 
    DONE 
};

struct ProccessInfo
{
    char proccess_name[30];
    enum Status status;
};

struct ListNode
{
    struct ProccessInfo proccess_info;
    struct ListNode *next;
};

typedef struct{
    int size;
    struct ListNode *head;
}LinkedList;


LinkedList init();
struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, struct ProccessInfo proccess_info, int index);

void pushfront(LinkedList *list, struct ProccessInfo proccess_info);

void pop(LinkedList *list, int index);
void popfront(LinkedList *list);

void setStatus(LinkedList *list, struct ProccessInfo proccess_info, enum Status new_status, int index);

#endif 