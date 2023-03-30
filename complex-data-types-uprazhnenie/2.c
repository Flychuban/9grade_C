#include <stdio.h>

// enum days {
//     MONDAY = 1,
//     TUESDAY,
//     WEDNESDAY,
//     THURSDAY,
//     FRIDAY,
//     SATURDAY,
//     SUNDAY
// };

enum days
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(){
    enum days number;
    do
    {
        printf("Enter a number 1 - 7: ");
        scanf("%d", &number);
    } while (number<1 || number>7);

    switch(number){
        case MONDAY:
            printf("Day in week: MONDAY");
            break;
        case TUESDAY: 
            printf("Day in week: TUESDAY");
            break;
        case WEDNESDAY:
            printf("Day in week: WEDNESDAY");
            break;
        case THURSDAY:
            printf("Day in week: THURSDAY");
            break;
        case FRIDAY:
            printf("Day in week: FRIDAY");
            break;
        case SATURDAY:
            printf("Day in week: SATURDAY");
            break;
        case SUNDAY:
            printf("Day in week: SUNDAY");
            break;
        }
    return 0;
}