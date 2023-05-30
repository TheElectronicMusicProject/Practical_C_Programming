#include <stdio.h>

static void get_data(int g_data[]);

static char g_line[100] = { 0 };
int seven_count = 0;
static int g_data[5] = { 0 };
int three_count = 0;
int index;

int
main (int argc, char * argv[])
{
    get_data(g_data);

    for (index = 1; index <= 5; ++index)
    {
        if (3 == g_data[index])
        {
            ++three_count;
        }

        if (7 == g_data[index])
        {
            ++seven_count;
        }
    }

    printf("Threes %d, Sevens %d\n", three_count, seven_count);

    return (0);
}

static void
get_data (int g_data[])
{
    printf("Enter 5 numbers\n");
    fgets(g_line, sizeof(g_line), stdin);
    sscanf(g_line, "%d %d %d %d %d",
           &g_data[1], &g_data[2], &g_data[3], &g_data[4], &g_data[5]);
    return;
}