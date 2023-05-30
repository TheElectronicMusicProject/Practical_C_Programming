#include <stdio.h>
#include <string.h>

int
main (int argc, char * argv[])
{
    char    line[100] = { 0 };

    while (1)
    {
        printf("Insert a number: ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';

        int idx = 0;

        for (idx = 0; line[idx] != '\0'; ++idx)
        {
            switch (line[idx])
            {
                case '0':
                    printf("zero");
                break;

                case '1':
                    printf("one");
                break;

                case '2':
                    printf("two");
                break;

                case '3':
                    printf("three");
                break;

                case '4':
                    printf("four");
                break;

                case '5':
                    printf("five");
                break;

                case '6':
                    printf("six");
                break;

                case '7':
                    printf("seven");
                break;

                case '8':
                    printf("eight");
                break;

                case '9':
                    printf("nine");
                break;

                default:
                    printf("What %d ??", line[idx]);
                break;
            }
            printf(" ");
        }
        printf("\n");
    }

    return (0);
}