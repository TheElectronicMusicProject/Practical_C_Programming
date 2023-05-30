#include <stdio.h>

int
main (int argc, char * argv[])
{
    char    line[100];
    int     seven_count = 0;
    int     data[5];
    int     three_count = 0;
    int     index;

    printf("enter 5 numbers\n");

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d %d %d %d", &data[0], &data[1], &data[2], &data[3], &data[4]);

    for (index = 0; index < 5; index++)
    {
        if (data[index] == 3)
            ++three_count;

        if (data[index] == 7)
            ++seven_count;
    }

    printf("Threes %d, Sevens %d\n", three_count, seven_count);

    return (0);
}