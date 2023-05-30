#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    int         number = 0;
    int         count = 0;
    int         ret_flag = 0;
    char        line[100] = { 0 };

    while (1)
    {
        printf("Insert a number:\t");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &number);

        count = number - 1;
        ret_flag = 0;

        while (count > 1)
        {
            if (0 == number % count)
            {
                ret_flag = 1;
                printf("Il numero non e' primo\n");
                break;
            }

            --count;
        }

        if (0 == ret_flag)
        {
            printf("Il numero e' primo!\n");
        }
    }

    return (0);
}