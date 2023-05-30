#include <stdio.h>
#include <string.h>

char * extended_fgets(char * line, int size, FILE * h_file);

#define STRING_LENGTH   (80)

FILE * gh_save_file = NULL;

int
main (void)
{
    char name[STRING_LENGTH] = { 0 };

    int lookup(char const * const name);

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
    
    gh_save_file = fopen("ouput.txt", "a");

    result = fgets(line, size, h_file);

    if (gh_save_file != NULL)
    {
        fputs(line, gh_save_file);

        fclose(gh_save_file);
    }

    return (result);
}