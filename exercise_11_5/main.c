#include <stdio.h>

int
main (void)
{
    char        line[100] = { 0 };
    long int    num = 0;
    
    while (1)
    {
        int         idx = 0;
        long int    mask = 0xF;
        int         temp_num = 0;
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%ld", &num);

        for (idx = 0; idx < 8; ++idx, mask <<= 4)
        {
            temp_num = (mask & num) >> (idx * 4);
            printf("%d: %d\n", idx, temp_num);
        }
    }

    return (0);
}