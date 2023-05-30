#include <stdio.h>
#include <stdlib.h>
#ifndef __MSDOS__
#   include <unistd.h>
#endif /* __MSDOS__ */

int
main (void)
{
    int cur_char;
    FILE * h_out_file;

    h_out_file = fopen("test.out", "wb");

    if (NULL == h_out_file)
    {
        fprintf(stderr, "Cannot open output file\n");
        exit(8);
    }

    for (cur_char = 0; cur_char < 128; ++cur_char)
    {
        fputc(cur_char, h_out_file);
    }

    fclose(h_out_file);

    return (0);
}