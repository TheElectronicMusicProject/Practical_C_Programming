#include <stdio.h>
#include <string.h>

static unsigned char
begin (char * string1, char * string2)
{
    int idx = 0;
    unsigned char ret = 0;

    for (idx = 0; idx < strlen(string1); ++idx)
    {
        if (string1[idx] != string2[idx])
        {
            ret = 1;
            break;
        }
    }

    return ret;
}

int
main (int argc, char * argv[])
{
    char    line1[100] = { 0 };
    char    line2[100] = { 0 };

    while (1)
    {
        printf("Write first string: ");
        fgets(line1, sizeof(line1), stdin);
        line1[strlen(line1) - 1] = '\0';

        printf("Write second string: ");
        fgets(line2, sizeof(line2), stdin);
        line2[strlen(line2) - 1] = '\0';

        if (0 == begin(line1, line2))
        {
            printf("%s inizia %s\n", line1, line2);
        }
        else
        {
            printf("No\n", line1, line2);
        }
    }

    return (0);
}