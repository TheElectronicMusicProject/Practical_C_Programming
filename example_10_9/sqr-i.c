#include <stdio.h>

#define SQR(x) ((x) * (x))

int
main (void)
{
    int counter = 0;

    while (counter < 5)
        printf("x %d square %d\n", counter, SQR(++counter));

    return (0);
}