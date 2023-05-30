#include <string.h>
#include <stdio.h>

int
main (void)
{
    char first[100];
    char last[100];
    char full_name[200];

    strcpy(first, "Filippo");
    strcpy(last, "Graziani");

    strcpy(full_name, first);
    strcat(full_name, " ");
    strcat(full_name, last);

    printf("The full name is %s\n", full_name);

    return (0);
}