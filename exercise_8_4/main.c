#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    int     idx1 = 0;
    int     idx2 = 0;

    for (idx1 = 0; idx1 < 10; idx1++)
    {
        for (idx2 = 0; idx2 < 10; idx2++)
        {
            printf("%d\t", (idx1 + 1) * (idx2 + 1));
        }
        printf("\n");
    }

    return (0);
}