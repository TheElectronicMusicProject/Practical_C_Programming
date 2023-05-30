#include <stdio.h>
#include <string.h>

int
main (int argc, char ** argv)
{
    int old_number;
    int current_number;
    int next_number;

    current_number = 1;
    old_number = 1;
    next_number = 1;

    printf("%d\n", next_number);

    while (100 >= next_number)
    {
        printf("%d\n", next_number);

        old_number = current_number;
        current_number = next_number;

        next_number = current_number + old_number;
    }

    return (0);
}