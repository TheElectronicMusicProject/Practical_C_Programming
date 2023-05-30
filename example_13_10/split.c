#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *
my_strchr (char * string_ptr, char find)
{
    while (find != *string_ptr)
    {
        if ('\0' == *string_ptr)
        {
            return (NULL);
        }

        ++string_ptr;
    }

    *string_ptr = '\0';

    ++string_ptr;

    return (string_ptr);
}

int
main (void)
{
    char line[80];
    char * first_ptr;
    char * last_ptr;

    fgets(line, sizeof(line), stdin);

    line[strlen(line) - 1] = '\0';

    last_ptr = line;

    first_ptr = my_strchr(line, '/');

    if (NULL == first_ptr)
    {
        fprintf(stderr, "Error: unable to find slash in %s\n", line);
        exit(8);
    }

    printf("First: %s Last: %s", first_ptr, last_ptr);

    return (0);
}