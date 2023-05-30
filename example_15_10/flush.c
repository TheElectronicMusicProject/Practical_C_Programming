#include <stdio.h>

int
main (int argc, char * argv[])
{
    int i, j;

    i = 1;
    j = 0;

    printf("Starting\n");
    fflush(stdout);

    printf("Before divide...");
    fflush(stdout);

    i = i / j;

    printf("After\n");
    fflush(stdout);

    return (0);
}