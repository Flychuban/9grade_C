#include <stdio.h>
#include <stdlib.h>
#include "bitstate.h"

int main()
{
    char op;
    char pos;
    do
    {
        printf("1. Turn on a diode\n");
        printf("2. Turn off a diode\n");
        printf("3. Switch a diode\n");
        printf("4. Check the state of a diode\n");
        printf("5. Print the states of all diodes\n");
        printf("6. Quit\n");
        printf("Choose an option (1, 2, 3, 4, 5 or 6): ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nChoose a position (1-32): ");
            scanf("%d", &pos);

            SetBit(pos);

            break;

        case 2:
            printf("\nChoose a position (1-32): ");
            scanf("%d", &pos);

            UnSetBit(pos);

            break;

        case 3:
            printf("\nChoose a position (1-32): ");
            scanf("%d", &pos);

            ToggleBit(pos);

            break;

        case 4:
            printf("\nChoose a position (1-32): ");
            scanf("%d", &pos);

            char temp = IsBitSet(pos);

            if (temp == 0)
                printf("\nDiode is turned off!\n");
            else if (temp == 1)
                printf("\nDiode is turned on!\n");
            else
                printf("\nThere is no such diode!\n");

            break;

        case 5:
            printf("\n Result: %u\n", GetBitState());

            break;

        case 6:
            break;

        default:
            printf("\nInvalid option!\n");
            break;
        }

        if (op == 6)
            break;

    } while (1);

    return 0;
}