#include "ia.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define NUMBER_OF_LINES 30
const int DATA_MIN = 1;
const int DATA_MAX = 30;
const int WIDTH = 60;

static struct infinite_array data_array;
static int data_items = 0;

int
main (int argc, char * argv[])
{
    void read_data(const char name[]);
    void print_histogram(void);

    if (argc != 2)
    {
        fprintf(stderr, "Errore\n");
        exit(8);
    }

    ia_init(&data_array);
    data_items = 0;
    read_data(argv[1]);
    print_histogram();

    return (0);
}

void
read_data (const char name[])
{
    char line[100] = {0};
    FILE * in_file = NULL;
    int data = 0;

    in_file = fopen(name, "r");
    if (NULL == in_file)
    {
        fprintf(stderr, "Error: open\n");
        exit(8);
    }

    while (1)
    {
        if (NULL == fgets(line, sizeof(line), in_file))
        {
            break;
        }

        if (1 != sscanf(line, "%d", &data))
        {
            fprintf(stderr, "Error: input\n");
        }

        ia_store(&data_array, data_items, data);
        ++data_items;
    }

    fclose(in_file);
}

void
print_histogram (void)
{
    int counters[NUMBER_OF_LINES] = {0};
    int out_of_range = 0;
    int max_count = 0;
    float scale = 0.0;
    int index = 0;

    memset(counters, '\0', sizeof(counters));

    for (index = 0; index < data_items; ++index)
    {
        int data = 0;
        data = ia_get(&data_array, index);

        if ((data < DATA_MIN) || (data > DATA_MAX))
        {
            ++out_of_range;
        }
        else
        {
            ++counters[data - DATA_MIN];
            if (counters[data - DATA_MIN] > max_count)
            {
                max_count = counters[data - DATA_MIN];
            }
        }
    }

    scale = ((float) max_count) / ((float) WIDTH);

    for (index = 0; index < NUMBER_OF_LINES; ++index)
    {
        int char_index = 0;
        int number_of_dots = 0;

        printf("%2d (%4d): ", index + DATA_MIN, counters[index]);

        number_of_dots = (int) (((float) counters[index]) / scale);

        for (char_index = 0; char_index < number_of_dots; ++char_index)
        {
            printf("*");
        }

        printf("\n");
    }

    printf("%d items out of range\n", out_of_range);
}