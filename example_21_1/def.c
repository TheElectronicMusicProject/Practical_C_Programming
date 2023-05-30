#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };

    while (1)
    {
        printf("Enter add(a), delete(d), quit(q): ");
        fgets(line, sizeof(line), stdin);

        switch (line[0])
        {
            case 'a':
                printf("Add\n");
            break;

            case 'd':
                printf("Delete\n");
            break;

            case 'q':
                printf("Quit\n");
                exit(0);
            break;

            default:
                printf("Error: bad command %c\n", line[0]);
            break;
        }
    }

    return (0);
}