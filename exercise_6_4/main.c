#include <stdio.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };
    double  money = 0.0;
    int     cents = 0;
    int     n_fifty = 0;
    int     n_twenty = 0;
    int     n_ten = 0;
    int     n_five = 0;
    int     n_two = 0;
    int     n_one = 0;

    while (1)
    {
        n_fifty = 0;
        n_twenty = 0;
        n_ten = 0;
        n_five = 0;
        n_two = 0;
        n_one = 0;

        printf("Inserire una cifra: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%lf", &money);

        money *= 100;

        cents = (float) money;

        if (cents < 0)
        {
            break;
        }
        
        while (cents > 0)
        {
            ++n_fifty;
            cents -= 50;
        }

        if (cents < 0)
        {
            --n_fifty;
            cents += 50;
        }

        while (cents > 0)
        {
            ++n_twenty;
            cents -= 20;
        }

        if (cents < 0)
        {
            --n_twenty;
            cents += 20;
        }

        while (cents > 0)
        {
            ++n_ten;
            cents -= 10;
        }

        if (cents < 0)
        {
            --n_ten;
            cents += 10;
        }

        while (cents > 0)
        {
            ++n_five;
            cents -= 5;
        }

        if (cents < 0)
        {
            --n_five;
            cents += 5;
        }

        while (cents > 0)
        {
            ++n_two;
            cents -= 2;
        }

        if (cents < 0)
        {
            --n_two;
            cents += 2;
        }

        while (cents > 0)
        {
            ++n_one;
            cents -= 1;
        }

        if (cents < 0)
        {
            --n_one;
            cents += 1;
        }

        printf("Il tuo importo e' di:\n");
        printf("%d da 50\n", n_fifty);
        printf("%d da 20\n", n_twenty);
        printf("%d da 10\n", n_ten);
        printf("%d da 5\n", n_five);
        printf("%d da 2\n", n_two);
        printf("%d da 1\n", n_one);
    }
    
    return (0);
}