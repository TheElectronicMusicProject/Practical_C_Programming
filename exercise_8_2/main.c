#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    int     n_res = 0;
    double  rtot = 0;
    char    line[100] = { 0 };
    double  r_array[20] = { 0 };

    while (1)
    {
        printf("Quante resistenze? ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &n_res);

        int idx = 0;

        for (idx = 0; idx < n_res; ++idx)
        {
            printf("Inserisci resistenza #%d [ohm]: ", idx);
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%lf", &r_array[idx]);
        }

        rtot = 0;

        for (idx = 0; idx < n_res; ++idx)
        {
            rtot += 1 / r_array[idx];
        }

        rtot = 1 / rtot;

        printf("Resistenza totale del parallelo = %lf ohm\n", rtot);
    }

    return (0);
}