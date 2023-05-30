#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    int         row = 0;
    int         column = 0;
    const int   nrow = 8 * (3 + 1) + 1;
    const int   ncolumn = 8 * (5 + 1) + 1;

    for (row = 0; row < nrow; ++row)
    {
        for (column = 0; column < ncolumn; ++column)
        {
            if (0 == (column % 6))
            {
                if (0 == (row % 4))
                {
                    printf("+");
                }
                else
                {
                    printf("|");
                }
            }
            else
            {
                if (0 == (row % 4))
                {
                    printf("-");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return (0);
}