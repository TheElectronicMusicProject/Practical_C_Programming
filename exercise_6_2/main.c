#include <stdio.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };
    int     grade = 0;

    while (1)
    {
        printf("Inserire un voto: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &grade);

        if (grade < 0)
        {
            printf("Bye bye...");
            break;
        }

        if ((grade >= 0) && (grade <= 60))
        {
            printf("Voto: F\n");
        }
        else if ((grade > 60) && (grade <= 70))
        {
            printf("Voto: D\n");
        }
        else if ((grade > 70) && (grade <= 80))
        {
            printf("Voto: C\n");
        }
        else if ((grade > 80) && (grade <= 90))
        {
            printf("Voto: B\n");
        }
        else if ((grade > 90) && (grade <= 100))
        {
            printf("Voto: A\n");
        }
        else
        {
            printf("Ellamadonna!\n");
        }
    }
    
    return (0);
}