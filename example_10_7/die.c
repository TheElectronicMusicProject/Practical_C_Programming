#include <stdio.h>
#include <stdlib.h>

#define DIE \
    fprintf(stderr, "Fatal error:Abort\n"); exit(8);

int
main (void)
{
    int value;

    value = 1;
    if (value < 0)
        DIE;

    printf("We did not die\n");

    return (0);
}