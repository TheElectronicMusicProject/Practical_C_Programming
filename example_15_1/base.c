#include <stdio.h>
#include <string.h>

#define STRING_LENGTH   (80)

int
main (void)
{
    char name[STRING_LENGTH] = { 0 };

    int lookup(char const * const name);

    while (1)
    {
        printf("Enter a name: ");
        fgets(name, sizeof(name), stdin);

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