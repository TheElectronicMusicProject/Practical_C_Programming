#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *
tmp_name (void)
{
    static char name[30];

    static int sequence = 0;

    strcpy(name, "tmp");

    name[3] = sequence + '0';

    name[4] = '\0';

    ++sequence;

    return (name);
}

int
main (void)
{
    printf("Name: %s\n", tmp_name());

    return (0);
}