#include <stdio.h>

int
main (int argc, char ** argv)
{
    int     total = 0;
    int     current = 0;
    int     counter;
    char    line[80];

    for (counter = 0; counter < 5; ++counter)
    {
        printf("Number? ");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &current);

        total += current;
    }

    printf("The grand total is %d\n", total);

    return (0);
}