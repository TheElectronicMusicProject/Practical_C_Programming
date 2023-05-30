#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    int     n_num = 0;
    float   n_average = 0;
    char    line[100] = { 0 };

    while (1)
    {
        printf("Quanti numeri? ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &n_num);

        int idx = 0;
        int num_array[n_num];

        for (idx = 0; idx < n_num; ++idx)
        {
            printf("Inserisci numero #%d: ", idx + 1);
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d", &num_array[idx]);
        }

        n_average = 0;

        for (idx = 0; idx < n_num; ++idx)
        {
            n_average += num_array[idx];
        }

        n_average /= n_num;

        printf("Valore medio = %f\n", n_average);
    }

    return (0);
}