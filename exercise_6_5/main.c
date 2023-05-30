#include <stdio.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };
    int     year = 0;
    int     leap = 0;

    while (1)
    {
        year = 0;

        printf("Inserire una cifra: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &year);

        if (year < 0)
        {
            break;
        }

        if (0 == (year % 4))
        {
            if (0 == (year % 100))
            {
                if (0 == (year % 400))
                {
                    leap = 1;
                }
                else
                {
                    leap = 0;
                }
            }
            else
            {
                leap = 1;
            }
        }
        else
        {
            leap = 0;
        }

        if (1 == leap)
        {
            printf("Anno bisestile\n");
        }
        else
        {
            printf("Anno non bisestile\n");
        }
    }
    
    return (0);
}