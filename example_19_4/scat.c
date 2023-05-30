#include <stdio.h>
#include <string.h>

char first[100];
char last[100];
char full[100];

int
main ()
{
    strcpy(first, "John");
    strcpy(last, "Doe");

    strcpy(full, first);
    strcat(full, ' ');
    strcat(full, last);

    printf("The name is %s\n", full);

    return (0);
}