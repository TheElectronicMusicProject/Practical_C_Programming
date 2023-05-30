#include <stdio.h>
#include <string.h>

static void
repair_string (char * string1)
{
    int idx = 0;
    
    for (idx = 0; idx < strlen(string1); ++idx)
    {
        string1[idx] = ('-' == string1[idx]) ? '_' : string1[idx];
    }

    return ;
}

int
main (int argc, char * argv[])
{
    char    line1[100] = { 0 };

    while (1)
    {
        printf("Write string: ");
        fgets(line1, sizeof(line1), stdin);
        line1[strlen(line1) - 1] = '\0';

        repair_string(line1);

        printf("%s\n", line1);
    }

    return (0);
}