#include <stdio.h>

const int HIGH_SPEED = (1 << 7);
const int DIRECT_CONNECT = (1 << 8);    // Errore!

int
main (void)
{
    char flags = 0;

    flags |= HIGH_SPEED;
    flags |= DIRECT_CONNECT;

    if (0 != (flags & HIGH_SPEED))
        printf("High speed set\n");

    if (0 != (flags & DIRECT_CONNECT))
        printf("Direct connect set\n");

    return (0);
}