#include <stdio.h>

#define FALSE   0
#define TRUE    1
#define IS_DIGIT(input, output)     {                                       \
                                    if ((input == '0') || (input == '1') || \
                                        (input == '2') || (input == '3') || \
                                        (input == '4') || (input == '5') || \
                                        (input == '6') || (input == '7') || \
                                        (input == '8') || (input == '9'))   \
                                    {                                       \
                                        output = TRUE;                      \
                                    }                                       \
                                    else                                    \
                                    {                                       \
                                        output =FALSE;                      \
                                    }                                       \
                                    }                                       \


int
main (int argc, char * argv[])
{
    char line[100] = { 0 };

    while (1)
    {
        int b_var = FALSE;

        fgets(line, sizeof(line), stdin);
        IS_DIGIT(line[0], b_var);

        if (b_var == TRUE)
        {
            printf("Bingo!\n");
        }
    }

    return (0);
}