#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     verbose = 0;
char *  out_file = "print.exe";
char *  program_name;
int     line_max = 66;

void
do_file (char * name)
{
    printf("Verbose %d Lines %d Input %s Output %s\n",
           verbose, line_max, name, out_file);
}

void
usage (void)
{
    fprintf(stderr, "Usage is %s [options] [file-list]\n", program_name);
    fprintf(stderr, "Options\n");
    fprintf(stderr, "   -v          verbose\n");
    fprintf(stderr, "   -l<number   Number of lines\n");
    fprintf(stderr, "   -o<name>    Set output filename\n");

    exit(8);
}

int
main (int argc, char * argv[])
{
    program_name = argv[0];

    while ((argc > 1) && (argv[1][0] == '-'))
    {
        switch (argv[1][1])
        {
            case 'v':
                verbose = 1;
            break;

            case 'o':
                out_file = &argv[1][2];
            break;

            case 'l':
                line_max = atoi(&argv[1][2]);
            break;

            default:
                fprintf(stderr, "Bad option %s\n", argv[1]);
                usage();
            break;
        }

        ++argv;
        --argc;
    }

    if (argc == 1)
    {
        do_file("print.c");
    }
    else
    {
        while (argc > 1)
        {
            do_file(argv[1]);
            ++argv;
            --argc;
        }
    }

    return (0);
}