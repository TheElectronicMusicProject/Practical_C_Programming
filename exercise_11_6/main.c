#include <stdio.h>

int
main (void)
{
    char    line[100] = { 0 };
    int     num = 0;
    
    while (1)
    {
        int idx = 0;
        int cnt = 0;
        int temp_num = 0;
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &num);

        for (idx = 0; idx < 32; ++idx)
        {
            if (num & (1 << idx))
            {
                ++cnt;
                temp_num |= (1 << (cnt - 1));
            }
        }

        printf("## cnt: %d\n", cnt);

        printf("## temp_num: %X\n", temp_num);

        temp_num <<= 32 - cnt;

        printf("## temp_num: %X\n", temp_num);
        printf("Risultato: %d\n", temp_num);
    }

    return (0);
}