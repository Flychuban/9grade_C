#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

typedef enum{
    NOEDUCATION,
    PRIMARY,
    SECONDARY,
    MASTER
} education;

typedef enum{
    SINGLE,
    MARRIED
} family;

typedef enum{
    UNEMPLOYED,
    WORKING
} work;


struct PersonInfo{
    int ID;
    int age;
    char name[255];
    education;
    family;
    work;
    struct PersonInfo *next;
};


typedef struct
{
    struct PersonInfo *head;
    int size;
} LinkedList;

LinkedList init();

void pushfront(LinkedList *list, struct PersonInfo person);
struct PersonInfo *get(LinkedList *list, int index);
void push(LinkedList *list, struct PersonInfo person, int index);
void pop(LinkedList *list, int ID);
void release(LinkedList *list);
#endif