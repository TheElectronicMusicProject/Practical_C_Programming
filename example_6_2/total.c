#include <stdio.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };
    int     total = 0;
    int     item = 0;

    while (1)
    {
        printf("Enter # to add \n");
        printf(" or 0 to stop: ");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &item);

        if (0 == item)
        {
            break;
        }

        total += item;
        printf("Total is %d\n", total);
    }

    printf("Final total is %d\n", total);
    
    return (0);
}