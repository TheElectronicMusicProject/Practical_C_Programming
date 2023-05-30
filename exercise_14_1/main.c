#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    FILE * h_file = fopen("input.txt", "r");
    int file_ch = 0;
    /* Esiste almeno una riga, considerando la presenza di EOF. */
    unsigned int counter = 1;

    if (NULL == h_file)
    {
        fprintf(stderr, "ERRORE!");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        file_ch = fgetc(h_file);

        if ('\n' == file_ch)
        {
            ++counter;
        }

        if (EOF == file_ch)
        {
            break;
        }
    }

    fclose(h_file);

    printf("Il numero di righe e' %u", counter);

    return (0);
}