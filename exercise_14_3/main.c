#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    char line[20] = { 0 };
    FILE * h_in_file = fopen("input.txt", "r");
    FILE * h_out_three = fopen("output_ok.txt", "w");
    FILE * h_out_nope = fopen("output_no.txt", "w");
    int file_ch = 0;
    char * p_ret = NULL;

    if (NULL == h_in_file)
    {
        fprintf(stderr, "File di input non apribile!");
        exit(EXIT_FAILURE);
    }

    if (NULL == h_out_three)
    {
        fclose(h_in_file);
        fprintf(stderr, "Errore sul file di uscita 1!");
        exit(EXIT_FAILURE);
    }

    if (NULL == h_out_nope)
    {
        fclose(h_in_file);
        fclose(h_out_three);
        fprintf(stderr, "Errore sul file di uscita 2!");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int number = 0;
        p_ret = fgets(line, sizeof(line), h_in_file);

        if (NULL == p_ret)
        {
            break;
        }

        sscanf(line, "%d", &number);

        if (EOF == file_ch)
        {
            break;
        }

        if (0 == number % 3)
        {
            sprintf(line, "%d\n", number);
            fwrite(line, strlen(line), 1, h_out_three);
        }
        else
        {
            sprintf(line, "%d\n", number);
            fwrite(line, strlen(line), 1, h_out_nope);
        }
    }

    fclose(h_in_file);
    fclose(h_out_nope);
    fclose(h_out_three);

    printf("FINE\n");

    return (0);
}