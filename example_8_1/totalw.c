#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    int     total = 0;
    int     current = 0;
    int     counter;
    char    line[80];

    while (counter < 5)
    {
        printf("Number? ");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &current);

        total += current;

        ++counter;
    }

    printf("The grand total is %d\n", total);

    return (0);
}