#include <stdio.h>

int
main (int argc, char * argv[])
{
    char    line[100];
    int     result = 0;
    char    operator;
    int     value;

    while (1)
    {
        printf("Result: %d\n", result);
        printf("Enter operator and number: ");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c %d", &operator, &value);

        if (('q' == operator) || ('Q' == operator))
        {
            break;
        }

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
                if (value == 0)
                {
                    printf("Error: divide by zero operation ignored\n");
                }
                else
                {
                    result /= value;
                }
            break;

            default:
                printf("Unknown operator %d\n", operator);
            break;
        }
    }

    return (0);
}