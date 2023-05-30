#include <stdio.h>
#include <string.h>

static int
max (int number, int * array, int length)
{
    if (0 == length)
    {
        return number;
    }

    if (array[0] > number)
    {
        number = array[0];
    }

    number = max(number, array + 1, length - 1);

    return number;
}

int
main (int argc, char * argv[])
{
    int array[100] = { 0 };
    char line[100] = { 0 };
    int idx = 0;

    while (1)
    {
        int res = 0;
        idx = 0;

        printf("Write a sequence (stop with a letter): ");

        while (1)
        {
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &array[idx]);

            if (0 > array[idx])
            {
                break;
            }
            else
            {
                ++idx;
            }
        }

        res = max(array[0], array, idx);
        printf("res = %d\n", res);
    }

    return (0);
}