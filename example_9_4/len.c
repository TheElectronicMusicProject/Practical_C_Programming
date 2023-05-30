#include <stdio.h>

int
length (char string[])
{
    int index;

    for (index = 0; string[index] != '\0'; ++index)
    {
        /* Do nothing */
    }

    return (index);
}

int
main (int argc, char * argv[])
{
    char line[100] = { 0 };

    while (1)
    {
        printf("Enter line: ");
        fgets(line, sizeof(line), stdin);

        printf("Length (including newline) is %d\n", length(line));
    }

    return (0);
}