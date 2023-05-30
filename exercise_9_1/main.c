#include <stdio.h>
#include <string.h>

int
main (int argc, char * argv[])
{
    char    line[100] = { 0 };

    while (1)
    {
        printf("Write something: ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';

        int idx = 0;
        int n_words = 0;

        for (idx = 0; line[idx] != '\0'; ++idx)
        {
            if ((' ' == line[idx]) && (' ' != line[idx + 1]) && (idx > 0) && ('\0' != line[idx + 1]))
            {
                ++n_words;
            }
        }

        ++n_words;

        printf("Number of words: %d\n", n_words);
    }

    return (0);
}