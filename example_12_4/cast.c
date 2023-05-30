#include <stdio.h>

int
main (void)
{
    int won, lost;
    float ratio;

    won = 5;
    lost = 3;

    ratio = won / lost;

    printf("#1 %f\n", ratio);

    ratio = ((float) won) / ((float) lost);

    printf("#2 %f\n", ratio);

    return (0);
}