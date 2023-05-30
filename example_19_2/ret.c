#include <stdio.h>

float square();

int
main (void)
{
    int i = square(5);

    printf("i is %d\n", i);

    return (0);
}

float
square (s)
int s;
{
    return (s * s);
}