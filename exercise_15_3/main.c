#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int * array;
    int n_el;
} array_t;

int
main (int argc, char ** argv)
{
    clock_t t_start = 0;
    clock_t t_stop = 0;
    char line[20] = { 0 };
    const char * p_file = "input.txt";
    array_t vect = { 0 };
    int idx = 0;
    register int total = 0;
    FILE * h_file = NULL;


    h_file = fopen(p_file, "r");

    if (NULL == h_file)
    {
        fprintf(stderr, "Errore apertura file %s\n", p_file);
        exit(EXIT_FAILURE);
    }

    fgets(line, sizeof(line), h_file);
    sscanf(line, "%d", &vect.n_el);

    vect.array = (int *) malloc(vect.n_el * sizeof(int));

    for (idx = 0; idx < vect.n_el; ++idx)
    {
        fgets(line, sizeof(line), h_file);
        sscanf(line, "%d", &vect.array[idx]);
        printf("idx=%d, %d\n", idx, vect.array[idx]);
    }

    t_start = clock();

    while (vect.n_el > 0)
    {
        total += *(vect.array + vect.n_el - 1);
        --vect.n_el;
    }

    t_stop = clock();

    printf("Total sum = %d\n", total);
    printf("Total time = %f seconds\n", ((float) (t_stop - t_start)) / (float) CLOCKS_PER_SEC);

    free(vect.array);
    fclose(h_file);

    return (0);
}