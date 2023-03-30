#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAXSYM 15

char* save_property(void){
    char *str = (char *)calloc(MAXSYM, sizeof(char));
    char *p;
    fgets(str, MAXSYM, stdin);
    p = strchr(str, '\n');
    if (*p == '\n')
        *p = '\0';

    return str;
}

void print_diary(char** subjects, int number_subjects, char** names, int number_students, int** marks){
    printf("\n               ");
    // for (int i = 0; i < number_subjects; i++)
    // {
    //     printf("%15s ", subjects[i]);
    // }
    for (int i = 0; i < number_subjects; i++)
    {
        printf("%15s ", *subjects[i]);
    }
    
    for (int i = 0; i < number_students; i++)
    {
        printf("\n%15s ", *names[i]);
        for (int j = 0; j < number_subjects; j++)
        {
            printf("%15d", marks[i][j]);
        }
        
    }
    
}

void quit(char** subjects, int number_subjects, char** names, int number_students, int** marks){
    for (int i = 0; i < number_subjects; i++)
    {
        free(subjects[i]);
    }
    free(subjects);

    for (int i = 0; i < number_students; i++)
    {
        free(names[i]);
    }
    free(names);

    for (int i = 0; i < number_students; i++)
    {
        free(names[i]);
    }
    free(names);

    free(marks);
}

int add_student(char **names, int number_students, int **marks, char **subjects, int number_subjects)
{
    number_students = number_students + 1;
    getchar();
    printf("\nName of student[%d]: ", number_students);
    names = (char **)realloc(names, number_students * sizeof(char *));
    names[number_students - 1] = save_property();
    

    marks = (int **)realloc(marks, number_students * sizeof(int *));
    marks[number_students - 1] = (int *)calloc(number_subjects, sizeof(int));
    int current_mark;
    for (int i = 0; i < number_subjects; i++)
    {
    printf("here");
        do
        {
            printf("\nMark for %s: ", subjects[i]);
            scanf("%d", &current_mark);
        } while (current_mark < 2 || current_mark > 6);
        marks[number_students - 1][i] = current_mark;
    }
    return number_students;
}

int main(){
    int number_subjects;
    int number_students = 0;
    do
    {
        printf("\nNumber subjects: ");
        scanf("%d", &number_subjects);
    } while (number_subjects<1 || number_subjects>INT_MAX);
    getchar();
    
    char **subjects = (char**)calloc(number_subjects, sizeof(char*));

    for (int i = 0; i < number_subjects; i++)
    {
        printf("\n Name subject[%d]: ", i+1);
        subjects[i] = save_property();
    }

    char **names = (char **)calloc(number_students, sizeof(char *));
    int **marks = (int **)calloc(number_students, sizeof(int *));
    
    char finish = 1;
    while (finish)
    {
        char izbor;
        printf("\n1. Add student");
        printf("\n2. Print diary");
        printf("\n3. Exit");
        printf("\n Choose: ");
        scanf("%d", &izbor);

        switch (izbor)
        {
        case 1:
            number_students = add_student(names, number_students, marks, subjects, number_subjects);
            break;
        case 2:
            print_diary(subjects, number_subjects, names, number_students, marks);
            break;
        case 3:
            quit(subjects, number_subjects, names, number_students, marks);
            finish = 0;
            break;
        }
    }
    return 0;
}
