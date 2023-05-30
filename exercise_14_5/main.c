#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    FILE * h_input = fopen("input.txt", "r");
    FILE * h_output = fopen("output.txt", "w");
    int character = 0;

    if (NULL == h_input)
    {
        fprintf(stderr, "File di input non apribile!");
        exit(EXIT_FAILURE);
    }

    if (NULL == h_output)
    {
        fclose(h_input);
        fprintf(stderr, "Errore sul file di uscita!");
        exit(EXIT_FAILURE);
    }

    do
    {
        character = fgetc(h_input);

        if (0 == (character & (1 << 7)))
            fputc(character, h_output);

    } while (character != EOF);
    

    fclose(h_input);
    fclose(h_output);

    printf("FINE\n");

    return (0);
}