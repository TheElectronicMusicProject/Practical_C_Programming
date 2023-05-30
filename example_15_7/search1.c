#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS     1000

const char g_data_file[] = "numbers.dat";

int g_data[MAX_NUMBERS];
int g_max_count;

int
main (int argc, char * argv[])
{
    FILE * in_file;
    int middle;
    int low, high;
    int search;
    char line[80];

    in_file = fopen(g_data_file, "r");

    if (NULL == in_file)
    {
        fprintf(stderr, "Error: unable to open %s\n", g_data_file);
        exit(8);
    }

    g_max_count = 0;

    while (1)
    {
        if (NULL == fgets(line, sizeof(line), in_file))
        {
            break;
        }

        sscanf(line, "%d", &g_data[g_max_count]);
        ++g_max_count;
    }

    while (1)
    {
        printf("Enter number to search for or -1 to quit: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &search);

        if (-1 == search)
        {
            break;
        }

        low = 0;
        high = g_max_count;

        while (1)
        {
            if (low > high)
            {
                printf("Not found\n");
                break;
            }

            middle = (low + high) / 2;

            if (search == g_data[middle])
            {
                printf("Found at index %d\n", middle);
                break;
            }

            if (g_data[middle] < search)
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
    }

    return (0);
}