#include <stdio.h>

int main(){
    
    // 0000 0000
    unsigned char rooms = 0;

    // 0000 0001 << 0 -> 0000 0001 = 1
    unsigned char room1 = 1 << 0;

    // 0000 0001 << 1 -> 0000 0010 = 2
    unsigned char room2 = 1 << 1;

    // 0000 0001 << 2 -> 0000 0100 = 4
    unsigned char room3 = 1 << 2;

    // 0000 0001 << 3 -> 0000 1000 = 8
    unsigned char room4 = 1 << 3;

    // 0000 0001 << 4 -> 0001 0000 = 16
    unsigned char room5 = 1 << 4;

    // 0000 0001 << 5 -> 0010 0000 = 32
    unsigned char room6 = 1 << 5;

    // 0000 0001 << 6 -> 0100 0000 = 64
    unsigned char room7 = 1 << 6;

    // 0000 0001 << 7 -> 1000 0000 = 128
    unsigned char room8 = 1 << 7;

    // Turns the light in room 4
    //   0000 0000
    //   0000 1000 
    // | 0000 1000
    rooms = rooms | room4;

    int roomnum = 6;
    // Turns the light in roomnum
    //  0000 1000
    //  0010 0000
    //| 0010 1000
    rooms = rooms | 1 << (roomnum - 1);


    //  0010 1000
    //  0000 1000
    //& 0000 1000
    // Checks whether the light are on in room 4
    printf("Is lights in room 4 turned on: %d", (rooms & room4) == room4);

    // Checks whether the lights are on in roomnum
    rooms & (1 < (roomnum - 1) == 1 << (roomnum - 1));
    printf("\n %d", rooms);
    
    return 0;
}