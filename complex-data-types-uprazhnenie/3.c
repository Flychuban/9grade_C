#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct{
    int number;
    double avg_mark;
    char name[15];
} Student;

typedef struct{
    Student all_students[10000];
    int count_students;
} Students;

void add_student(Students *students){
    char save_name[15];
    char *p;
    printf("\nEnter student number: ");
    scanf("%d", &students->all_students[students->count_students].number);
    getchar();
    printf("\nEnter student name: ");
    fgets(save_name, 15, stdin);
    if (p = strchr(save_name, '\n'))
        *p = '\0';
    strcpy(students->all_students[students->count_students].name, save_name);
    double new_avg_mark;
    do
    {
        printf("\nEnter student avg_mark: ");
        scanf("%lf", &new_avg_mark);
    } while (new_avg_mark < 2 || new_avg_mark > 6);
    students->all_students[students->count_students].avg_mark = new_avg_mark;

    students->count_students++;
}

void print_students(Students *students){
    for(int i = 0; i < students->count_students; i++){
        printf("\nStudent number: %d", students->all_students[i].number);
        printf("\nStudent name: %s", students->all_students[i].name);
        printf("\nStudent avg_mark: %.3lf", students->all_students[i].avg_mark);
        printf("\n------------------------");
    }
}


int main(){
    Students students = {count_students: 0};
    int option = 0;
    while(option != 3){
        printf("\n1. Add student");
        printf("\n2. Print students");
        printf("\n3. Exit");
        printf("\nChoose option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                add_student(&students);
                break;
            case 2:
                print_students(&students);
                break;
            default:
                printf("Invalid option");
        }
    }
    printf("\nGoodbye!");
    return 0;
}