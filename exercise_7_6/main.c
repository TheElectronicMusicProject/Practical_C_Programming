#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    int         negative = 0;
    int         positive = 0;
    int         numbers[20] = { 0 };
    char        line[100] = { 0 };
    int         idx = 0;

    while (1)
    {
        idx = 0;
        positive = 0;
        negative = 0;

        do
        {
            printf("Insert num[%d]: ", idx);
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &numbers[idx]);
            ++idx;
        } while ((0 != numbers[idx - 1]) || (20 == idx));

        --idx;
        
        while (idx >= 0)
        {
            if (numbers[idx] > 0)
            {
                ++positive;
            }
            else if (numbers[idx] < 0)
            {
                ++negative;
            }
            --idx;
        }

        printf("there are %d positives, %d negatives\n", positive, negative);
    }

    return (0);
}