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

        switch (operator)
        {
            case '+':
                result += value;
            break;

            case '-':
                result -= value;
            break;

            case '*':
                result *= value;
            break;

            case '/':
                if (0 == value)
                {
                    printf("Error: divide by zero operation failed\n");
                }
                else
                {
                    result /= value;
                }
            break;

            case 'q':
                /* Fall through. */
            case 'Q':
                return (0);
            break;

            default:
                printf("Unknown opeator %c\n", operator);
            break;
        }
    }

    return (0);
}