#include <stdio.h>
#include <string.h>

char *
find_string (char * p_string)
{
    if (p_string == NULL)
    {
        return NULL;
    }
    
    while (*p_string == ' ')
    {
        ++p_string;
    }

    return p_string;
}

int
main (int argc, char ** argv)
{
    char line[80];
    char * p_new = NULL;

    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    
    p_new = find_string(line);

    if (p_new != NULL)
    {
        printf("senza spazi: %s\n", p_new);
    }

    return (0);
}