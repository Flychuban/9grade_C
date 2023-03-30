#include <stdio.h>
#include <stdlib.h>

#define FAILED_TO_ALLOCATE_MEMORY 1
#define ARR_TOO_SHORT 2

void print_ocenki(float * arr_ocenki, int marks_count){
    printf("\n");
    for (int i = 0; i < marks_count; i++)
    {
        printf("%.2f ", arr_ocenki[i]);
    }
    
}

int quit(float * arr_ocenki){
    free(arr_ocenki);
}

void average_mark(float * arr_ocenki, int marks_count){
    float sum = 0;
    for (int i = 0; i < marks_count; i++)
    {
        sum += arr_ocenki[i]; 
    }
    
    printf("\n Average mark: %.2f", sum/marks_count);    
}

void add_mark(float * arr_ocenki, int * marks_count){
    *marks_count = *marks_count + 1;
    arr_ocenki = (float *)realloc(arr_ocenki, *marks_count * sizeof(float));

    if (arr_ocenki == NULL)
    {
        printf("\nError!");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }

    float new_mark;
    do
    {
        printf("Mark[%d]: ", *marks_count);
        scanf("%f", &new_mark);
    } while (new_mark < 2 || new_mark > 6);
    arr_ocenki[*marks_count - 1] = new_mark;
}

void remove_mark(float * arr_ocenki, int * marks_count){
    if (*marks_count == 1)
    {
        printf("\n Minimum number marks is reached! Can't remove more marks!");
    }
    
    else{
        *marks_count = *marks_count - 1;
        arr_ocenki = (float *)realloc(arr_ocenki, *marks_count * sizeof(float));

        if (arr_ocenki == NULL)
        {
            printf("\nError!");
            exit(FAILED_TO_ALLOCATE_MEMORY);
        }
    }
}

int main(){
    int marks_count;
    do
    {
        printf("\nNumber marks: ");
        scanf("%d", &marks_count);
    } while (marks_count < 1 || marks_count > 100);
    
    float *arr_ocenki = (float *)calloc(marks_count, sizeof(float));
    if(arr_ocenki == NULL){
        printf("\nError!");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }

    for (int  i = 0; i < marks_count; i++)
    {
        float current_mark;
        do
        {
            printf("\n Mark[%d]: ", i+1);
            scanf("%f", &current_mark);
        } while (current_mark < 2 || current_mark > 6);
        
        arr_ocenki[i] = current_mark;
    }
    
    char finish = 1;
    while (finish)
    {
        char izbor;
        printf("\n1. Average mark");
        printf("\n2. Add new mark");
        printf("\n3. Remove last mark");
        printf("\n4. Print all marks");
        printf("\n5. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);

        switch (izbor)
        {
        case 1: average_mark(arr_ocenki, marks_count); break;
        case 2: add_mark(arr_ocenki, &marks_count); break;
        case 3: remove_mark(arr_ocenki, &marks_count); break;
        case 4: print_ocenki(arr_ocenki, marks_count); break;
        case 5: quit(arr_ocenki); finish=0; break;
        default: printf("\nInvalid option!"); break;
        }
    }
    return 0;
}