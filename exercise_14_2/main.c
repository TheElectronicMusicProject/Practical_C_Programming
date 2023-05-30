#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    FILE * h_in_file = fopen("input.txt", "r");
    FILE * h_out_file = fopen("output.txt", "w");
    int file_ch = 0;

    if (NULL == h_in_file)
    {
        fprintf(stderr, "File di input non apribile!");
        exit(EXIT_FAILURE);
    }

    if (NULL == h_out_file)
    {
        fprintf(stderr, "Errore sul file di uscita!");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        file_ch = fgetc(h_in_file);

        if ('\t' == file_ch)
        {
            int i = 0;

            for (i = 0; i < 4; ++i)
            {
                fputc(' ', h_out_file);
            }
        }
        else
        {
            if (EOF == file_ch)
            {
                break;
            }
            else
            {
                fputc(file_ch, h_out_file);
            }
        }
    }

    fclose(h_in_file);
    fclose(h_out_file);

    printf("FINE\n");

    return (0);
}