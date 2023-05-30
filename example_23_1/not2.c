#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    char line[80];
    int number;

    printf("Enter a number: ");

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &number);

    if (number =! 2)
    {
        printf("Number is not two\n");
    }
    else
    {
        printf("Number is two\n");
    }

    return (0);
}