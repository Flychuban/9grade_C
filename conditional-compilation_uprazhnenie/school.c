#include <stdio.h>
#include <string.h>

#include "schoolroom.h"
#include "schoolclass.h"

typedef struct{
    SchoolClass classes[20];
    SchoolRoom rooms[10];
}School;

int main(){
    School school;
    school.classes->class_number=9;
    school.classes->class_symbol='a';
    school.rooms->room_number=9113;
    strcpy(school.classes->teacher->first_name, "Ivanka");
    strcpy(school.classes->teacher->second_name, "Petrova");
    strcpy(school.classes->teacher->last_name, "Ivanova");
    strcpy(school.rooms->people_room[0].first_name, "Grisho");
    strcpy(school.rooms->people_room[0].second_name, "Qvorov");
    strcpy(school.rooms->people_room[0].last_name, "Grishov");
    school.rooms->people_room[0].birth_year = 2007;

    printf("%d\n", school.classes->class_number);
    printf("%c\n", school.classes->class_symbol);
    printf("%d\n", school.rooms->room_number);
    printf("%s ", school.classes->teacher->first_name);
    printf("%s ", school.classes->teacher->second_name);
    printf("%s\n", school.classes->teacher->last_name);
    printf("%s ", school.rooms->people_room[0].first_name);
    printf("%s ", school.rooms->people_room[0].second_name);
    printf("%s ", school.rooms->people_room[0].last_name);
    printf(" - %d", school.rooms->people_room[0].birth_year);
    return 0;
}