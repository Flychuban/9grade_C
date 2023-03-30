#include <stdio.h>

int main()
{
    unsigned char on_lights = 189;

    printf("Off lights: ");
    for (int i = 0; i <= 7; i++)
    {
        int new_light = 1 << i;
        if ((on_lights & new_light) != new_light) // checks whether room N is OFF
        {
            printf(" %d", i + 1);
        }
    }
    return 0;
}