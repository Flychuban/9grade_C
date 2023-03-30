#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Answer
{
    NO = 0,
    YES = 1
};

typedef struct
{
    char first_name[30];
    char second_name[30];
    char last_name[30];
    char email[30];
    char phone[10];
} Participant;

typedef struct
{
    Participant participant;
    enum Answer answer;
} ParticipantsAnswers;

typedef struct
{
    struct
    {
        int day;
        int month;
        int year;
        int hour;
    } date;

    char title[30];
    char description[10000];
    ParticipantsAnswers all_participants[100];
} Causes;

typedef struct
{
    Causes all_causes[10000];
    int active_causes_count;
} AllCauses;

int main()
{
    printf("Hello World!");
    // char generated_text[10000] = "On April 1st, 2023 at 10am, we will be planting trees in South Park! Trees provide countless benefits to our environment, from cleaning the air we breathe to providing shade and shelter for wildlife. By planting trees in our community we are not only enhancing the natural beauty of our surroundings but also improving the health of our planet. We invite everyone to come out and help us plant trees in South Park. This is a great opportunity to get involved in the community and make a positive impact on our environment. Let's work together to create a greener, more sustainable future for ourselves and future generations. See you there!";

    // Causes planting_trees = {
    //     .date.day = 1,
    //     .date.month = 4,
    //     .date.year = 2023,
    //     .date.hour = 10,
    //     .title = "Planting trees in the park",
    //     .description = "On April 1st, 2023 at 10am, we will be planting trees in South Park! Trees provide countless benefits to our environment, from cleaning the air we breathe to providing shade and shelter for wildlife. By planting trees in our community we are not only enhancing the natural beauty of our surroundings but also improving the health of our planet. We invite everyone to come out and help us plant trees in South Park. This is a great opportunity to get involved in the community and make a positive impact on our environment. Let's work together to create a greener, more sustainable future for ourselves and future generations. See you there!",

    //     .all_participants[0] = {
    //         .participant = {
    //             .first_name = "Ivan",
    //             .second_name = "Ivanov",
    //             .last_name = "Ivanov",
    //             .email = "ivanivanov@abv.bg",
    //             .phone = "08888888"
    //             },
    //         .answer = YES
    //         },

    //     .all_participants[1] = {
    //         .participant = {
    //             .first_name = "Georgi", 
    //             .second_name = "Ivanov", 
    //             .last_name = "Georgiev", 
    //             .email = "georgifeorgiev@abv.bg", 
    //             .phone = "0111111"
    //             }, 
    //         .answer = YES
    //         },

    //     .all_participants[2] = {
    //         .participant = {
    //             .first_name= "Maria", 
    //             .second_name = "Ivanova",
    //             .last_name = "Petkova", 
    //             .email = "maria@abv.bg", 
    //             .phone = "0222222"
    //             }, 
    //         .answer = NO
    //         },

    //     .all_participants[3] = {
    //         .participant = {
    //             .first_name = "Alex", 
    //             .second_name = "Ivanov", 
    //             .last_name = "Petkov", 
    //             .email = "alex@abv.bg", 
    //             .phone = "03333333"
    //             }, 
    //         .answer = YES
    //         },
        
    //     .all_participants[4] = {
    //         .participant = {
    //             .first_name= "Lora", 
    //             .second_name = "Ivanova", 
    //             .last_name = "Ivanova", 
    //             .email = "lora@gmail.com", 
    //             .phone = "0111111"
    //             },
    //         .answer = NO
    //         },
    // };

    // Causes cleaning_the_beach = {
    //     .date.day = 2,
    //     .date.month = 6,
    //     .date.year = 2023,
    //     .date.hour = 9,
    //     .title = "Cleaning the beach",
    //     .description = "Let's clean the beach together!",
    //     .all_participants[0] = {
    //         .participant = {
    //             .first_name = "Borimir",
    //             .second_name = "Ivanov",
    //             .last_name = "Ganchev",
    //             .email = "borimir@gmail.com",
    //             .phone = "08888888"
    //             },
    //         .answer = NO
    //     },
    //     .all_participants[1] = {
    //         .participant = {
    //             .first_name = "Boris",
    //             .second_name = "Ivanov",
    //             .last_name = "Anastasov",
    //             .email = "bobi@gmail.com",
    //             .phone = "06666666"
    //             },
    //         .answer = YES
    //     },

    //     .all_participants[2] = {
    //         .participant = {
    //             .first_name = "Martin",
    //             .second_name = "Ivanov",
    //             .last_name = "Gluhchev",
    //             .email = "mg@gmail.com",
    //             .phone = "0777777"
    //             },
    //         .answer = YES
    //     }
    // };

AllCauses all_active_causes = {
    .all_causes[0] = {
        .date.day = 1,
        .date.month = 4,
        .date.year = 2023,
        .date.hour = 10,
        .title = "Planting trees in the park",
        .description = "On April 1st, 2023 at 10am, we will be planting trees in South Park! Trees provide countless benefits to our environment, from cleaning the air we breathe to providing shade and shelter for wildlife. By planting trees in our community we are not only enhancing the natural beauty of our surroundings but also improving the health of our planet. We invite everyone to come out and help us plant trees in South Park. This is a great opportunity to get involved in the community and make a positive impact on our environment. Let's work together to create a greener, more sustainable future for ourselves and future generations. See you there!",

        .all_participants[0] = {
            .participant = {
                .first_name = "Ivan",
                .second_name = "Ivanov",
                .last_name = "Ivanov",
                .email = "ivanivanov@abv.bg",
                .phone = "08888888"
                },
            .answer = YES
            },

        .all_participants[1] = {
            .participant = {
                .first_name = "Georgi", 
                .second_name = "Ivanov", 
                .last_name = "Georgiev", 
                .email = "georgifeorgiev@abv.bg", 
                .phone = "0111111"
                }, 
            .answer = YES
            },

        .all_participants[2] = {
            .participant = {
                .first_name= "Maria", 
                .second_name = "Ivanova",
                .last_name = "Petkova", 
                .email = "maria@abv.bg", 
                .phone = "0222222"
                }, 
            .answer = NO
            },

        .all_participants[3] = {
            .participant = {
                .first_name = "Alex", 
                .second_name = "Ivanov", 
                .last_name = "Petkov", 
                .email = "alex@abv.bg", 
                .phone = "03333333"
                }, 
            .answer = YES
            },
        
        .all_participants[4] = {
            .participant = {
                .first_name= "Lora", 
                .second_name = "Ivanova", 
                .last_name = "Ivanova", 
                .email = "lora@gmail.com", 
                .phone = "0111111"
                },
            .answer = NO
            }
    },

    .all_causes[1] = {
        .date.day = 2,
        .date.month = 6,
        .date.year = 2023,
        .date.hour = 9,
        .title = "Cleaning the beach",
        .description = "Let's clean the beach together!",
        .all_participants[0] = {
            .participant = {
                .first_name = "Borimir",
                .second_name = "Ivanov",
                .last_name = "Ganchev",
                .email = "borimir@gmail.com",
                .phone = "08888888"
                },
            .answer = NO
        },
        .all_participants[1] = {
            .participant = {
                .first_name = "Boris",
                .second_name = "Ivanov",
                .last_name = "Anastasov",
                .email = "bobi@gmail.com",
                .phone = "06666666"
                },
            .answer = YES
        },

        .all_participants[2] = {
            .participant = {
                .first_name = "Martin",
                .second_name = "Ivanov",
                .last_name = "Gluhchev",
                .email = "mg@gmail.com",
                .phone = "0777777"
                },
            .answer = YES
        }
    },

    .active_causes_count = 2
};
    
    printf("\n%d", all_active_causes.active_causes_count);
    printf("\nHere");
    return 0;
}