#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
    char name[100];
    FILE * p_in_file = NULL;

    printf("Name?");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    p_in_file = fopen(name, "r");

    if (NULL == p_in_file)
    {
        fprintf(stderr, "Error: Unable to open %s for input\n", name);
        exit(EXIT_FAILURE);
    }

    printf("File found\n");
    fclose(p_in_file);

    return (0);
}