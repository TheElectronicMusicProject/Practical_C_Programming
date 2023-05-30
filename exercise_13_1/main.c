#include <stdio.h>
#include <string.h>

int
main (void)
{
    int *   p_array = NULL;
    int     array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int     index = 0;

    p_array = array;

    for (index = 0; index < (sizeof(array) / sizeof(int)); ++index)
    {
        printf("#%d -> %d\n", index, array[index]);
    }

    for (index = 0; index < (sizeof(array) / sizeof(int)); ++index, ++p_array)
    {
        *(p_array) = 0;
    }

    for (index = 0; index < (sizeof(array) / sizeof(int)); ++index)
    {
        printf("#%d -> %d\n", index, array[index]);
    }

    return (0);
}