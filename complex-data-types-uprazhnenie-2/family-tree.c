#include <stdio.h>
#include <stdlib.h>

struct Node{
    char firstname[15];
    struct Node *dad;
    struct Node *mum;
    struct Node *marriedto;
};



int main(){

    struct Node me = {.firstname = "Kaloyan"};
    struct Node dad = {.firstname = "Chavdar"};
    struct Node mum = {.firstname = "Nicolina"};
    struct Node grandmum_1 = {.firstname = "Zhaneta"};
    struct Node granddad_1 = {.firstname = "Stoqn"};
    struct Node grandmum_2 = {.firstname = "Efimia"};
    struct Node granddad_2 = {.firstname = "Marin"};

    me.dad = &dad;
    me.mum = &mum;
    me.marriedto = NULL;

    dad.dad = &granddad_2;
    dad.mum = &grandmum_2;
    dad.marriedto = &mum;

    mum.dad = &granddad_1;
    mum.mum = &grandmum_1;
    mum.marriedto = &dad;

    granddad_1.dad = NULL;
    granddad_1.mum = NULL;
    granddad_1.marriedto = &grandmum_1;

    grandmum_1.dad = NULL;
    grandmum_1.mum = NULL;
    grandmum_1.marriedto = &granddad_1;

    granddad_2.dad = NULL;
    granddad_2.mum = NULL;
    granddad_2.marriedto = &grandmum_2;

    grandmum_2.dad = NULL;
    grandmum_2.mum = NULL;
    grandmum_2.marriedto = &granddad_2;


    printf("%s", me.dad->dad->marriedto->firstname);
    return 0;
}