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
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &num);

        for (idx = 0; idx < 32; ++idx, num >>= 1)
        {
            if (num & (1 << 0))
            {
                cnt++;
            }
        }

        printf("Number of ones: %d\n", cnt);
    }

    return (0);
}