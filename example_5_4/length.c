#include <string.h>
#include <stdio.h>

int
main (void)
{
    char line[100];

    printf("Enter a line: ");

    fgets(line, sizeof(line), stdin);

    printf("The length of the line is: %d\n", strlen(line));

    return (0);
}