#include <stdio.h>

#define RECIPROCAL (number)  (1.0 / (number))

int
main (void)
{
    int i1 = 4, i2 = 2;

    if ((i1 != 0) && (i2 != 0))
    {
        printf("Both are not zero\n");
    }

    if (i1 && i2)
    {
        printf("Both are not zero\n");
    }

    if (i1 & i2)
    {
        printf("Both are not zero\n");
    }

    return (0);
}