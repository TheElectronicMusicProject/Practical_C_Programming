#include <stdio.h>
#include <string.h>

#if 0
static int
count (int number, int * array, int length)
{
    int idx = 0;
    int cnt = 0;

    for (idx = 0; idx < length; ++idx)
    {
        if (number == array[idx])
        {
            ++cnt;
        }
    }

    return cnt;
}
#endif

static int
count (int number, int * array, int length)
{
    int cnt = 0;

    if (0 == length)
    {
        cnt = 0;
    }
    else
    {
        cnt += count(number, array + 1, length - 1);
    }

    return cnt;
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

        res = count(3, array, idx);
        printf("res = %d\n", res);
    }

    return (0);
}