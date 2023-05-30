#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * extended_fgets(char * line, int size, FILE * h_file);

#define STRING_LENGTH   (80)

FILE * gh_save_file = NULL;

int
main (int argc, char * argv[])
{
    char name[STRING_LENGTH] = { 0 };
    char * p_save_file_name = NULL;

    int lookup(char const * const name);

    while ((argc > 1) && ('-' == argv[1][0]))
    {
        switch (argv[1][1])
        {
            case 'S':
                p_save_file_name = &argv[1][2];
                gh_save_file = fopen(p_save_file_name, "w");
                if (NULL == gh_save_file)
                {
                    fprintf(stderr, "Warning: Unable to open save file %s\n",
                            p_save_file_name);
                }
            break;

            default:
                fprintf(stderr, "Bad option: %s\n", argv[1]);
                exit(8);
            break;
        }

        --argc;
        ++argv;
    }

    while (1)
    {
        printf("Enter a name: ");

        extended_fgets(name, sizeof(name), stdin);

        if (strlen(name) <= 1)
        {
            break;
        }

        name[strlen(name) - 1] = '\0';

        if (lookup(name))
        {
            printf("%s is in the list\n", name);
        }
        else
        {
            printf("%s is not in the list\n", name);
        }
    }

    if (NULL != gh_save_file)
    {
        fclose(gh_save_file);
    }

    return (0);
}

int
lookup (char const * const name)
{
    static char * list[] = {
        "John",
        "Jim",
        "Jane",
        "Clyde",
        NULL,
    };

    int index;

    for (index = 0; list[index] != NULL; ++index)
    {
        if (0 == strcmp(list[index], name))
        {
            return (1);
        }
    }

    return (0);
}

char *
extended_fgets (char * line, int size, FILE * h_file)
{
    char * result;

    result = fgets(line, size, h_file);

    if (gh_save_file != NULL)
    {
        fputs(line, gh_save_file);
    }

    return (result);
}