#include <stdio.h>

float
area (width, height)
float width;
float height;
{
    return (width * height);
}

int
main (void)
{
    float size = area(3.0 * 2.0);

    printf("Area is %f\n", size);

    return (0);
}