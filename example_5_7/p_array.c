#include <stdio.h>

int
main (void)
{
    int array[3][2];
    int x, y;

    array[0][0] = 0;
    array[0][1] = 1;
    array[1][0] = 10;
    array[1][1] = 11;
    array[2][0] = 20;
    array[2][1] = 21;

    printf("array[%d] ", 0);
    printf("%d ", array[0][0]);
    printf("%d ", array[0][1]);
    printf("\n");

    printf("array[%d] ", 1);
    printf("%d ", array[1][0]);
    printf("%d ", array[1][1]);
    printf("\n");

    printf("array[%d] ", 2);
    printf("%d ", array[2][0]);
    printf("%d ", array[2][1]);
    printf("\n");

    return (0);
}