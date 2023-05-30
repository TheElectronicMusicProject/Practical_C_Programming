#include <stdio.h>
#include <stdlib.h>

#define WRITE
#undef WRITE

const char file_name[] = "input.txt";

int
main (void)
{
    int count = 0;
    FILE * in_file;
    int ch;
#ifdef WRITE
    in_file = fopen(file_name, "w");
#else
    in_file = fopen(file_name, "r");
#endif /* WRITE */

    if (NULL == in_file)
    {
        fprintf(stderr, "Cannot open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
#ifdef WRITE
    fputc('a', in_file);
#else
    while (1)
    {
        ch = fgetc(in_file);
        if (EOF == ch)
        {
            break;
        }

        ++count;
    }

    fprintf(stdout, "Number of characters in %s is %d\n", file_name, count);
#endif /* WRITE */

    fclose(in_file);

    return (0);
}