#include <stdio.h>
#include <string.h>

int
main (int argc, char ** argv)
{
    int     result = 0.0;
    char    line[100] = { 0 };
    char    operator;
    int     value;

    while (1)
    {
        printf("Result: %d\n", result);

        printf("Enter operator and number: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c %d", &operator, &value);

        if ('+' == operator)
        {
            result += value;
        }
        else
        {
            printf("Unknown opeator %c\n", operator);
        }
    }

    return (0);
}