#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    char line[20] = { 0 };
    FILE * h_ascii = fopen("ascii.txt", "r");
    FILE * h_binary = fopen("bin.txt", "wb");
    size_t n_char = 0;

    if (NULL == h_ascii)
    {
        fprintf(stderr, "File di input non apribile!");
        exit(EXIT_FAILURE);
    }

    if (NULL == h_binary)
    {
        fclose(h_ascii);
        fprintf(stderr, "Errore sul file di uscita!");
        exit(EXIT_FAILURE);
    }

    do
    {
        n_char = fread(line, 1, sizeof(line), h_ascii);

        fwrite(line, 1, n_char, h_binary);
    } while (n_char > 0);

    fclose(h_ascii);
    fclose(h_binary);

    h_ascii = fopen("ascii2.txt", "w");
    h_binary = fopen("bin.txt", "rb");
    n_char = 0;

    if (NULL == h_ascii)
    {
        fprintf(stderr, "File di output non apribile!");
        exit(EXIT_FAILURE);
    }

    if (NULL == h_binary)
    {
        fclose(h_ascii);
        fprintf(stderr, "Errore sul file di ingresso!");
        exit(EXIT_FAILURE);
    }

    do
    {
        n_char = fread(line, 1, sizeof(line), h_binary);

        fwrite(line, 1, n_char, h_ascii);
    } while (n_char > 0);

    fclose(h_ascii);
    fclose(h_binary);

    printf("FINE\n");

    return (0);
}