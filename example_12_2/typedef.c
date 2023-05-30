#include <stdio.h>

union value
{
    long int i_value;
    float f_value;
} data;

int i;
float f;

int
main (void)
{
    int i = 0;
    typedef int group[10];

    group totals;

    for (i = 0; i < 10; i++)
    {
        totals[i] = i;
        printf("@%d, %d\n", i, totals[i]);
    }

    return (0);
}