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
        else
        {
            if ((grade > 60) && (grade <= 70))
            {
                grade -= 60;
                printf("Voto: D");
            }
            else if ((grade > 70) && (grade <= 80))
            {
                grade -= 70;
                printf("Voto: C");
            }
            else if ((grade > 80) && (grade <= 90))
            {
                grade -= 80;
                printf("Voto: B");
            }
            else if ((grade > 90) && (grade <= 100))
            {
                grade -= 90;
                printf("Voto: A");
            }
            else
            {
                grade = 0;
                printf("Ellamadonna!\n");
            }

            if (grade != 0)
            {
                if ((grade >= 1) && (grade <= 3))
                {
                    printf("-\n");
                }
                else if ((grade > 3) && (grade <= 7))
                {
                    printf("\n");
                }
                else if ((8 > 3) && (grade <= 10))
                {
                    printf("+\n");
                }
                else
                {
                    printf("\t :-/\n");
                }
            }
        }
    }
    
    return (0);
}