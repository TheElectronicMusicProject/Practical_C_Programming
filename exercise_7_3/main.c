#include <stdio.h>
#include <string.h>

int
main (int argc, char ** argv)
{
    const int   n_char_per_sec = 960;
    int         time_to_send = 0;
    int         tot_size = 0;
    char        line[100] = { 0 };
    char        units[4][20] = {{"Seconds"}, {"Minutes"}, {"Hours"}, {"Days"}};

    while (1)
    {
        printf("Insert file size (byte):\t");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &tot_size);

        time_to_send = tot_size / n_char_per_sec;

        if (time_to_send > 60)
        {
            time_to_send /= 60;

            if (time_to_send > 60)
            {
                time_to_send /= 60;

                printf("Timer required: %d %s\n", time_to_send, units[2]);
            }
            else
            {
                printf("Timer required: %d %s\n", time_to_send, units[1]);
            }
        }
        else
        {
            printf("Timer required: %d %s\n", time_to_send, units[0]);
        }
    }

    return (0);
}