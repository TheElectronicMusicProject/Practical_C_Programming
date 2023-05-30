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
    char * name1;
    char * name2;

    name1 = tmp_name();
    name2 = tmp_name();

    printf("Name1: %s\n", name1);
    printf("Name2: %s\n", name2);

    return (0);
}