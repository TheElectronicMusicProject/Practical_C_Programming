#include <stdio.h>

int
main (int argc, char * argv[])
{
    int counter;

    for (counter = 0; counter < 3; ++counter)
    {
        int         temporary = 1;
        static int  permanent = 1;

        printf("Temporary %d Permanent %d\n", temporary, permanent);
        ++temporary;
        ++permanent;
    }

    return (0);
}