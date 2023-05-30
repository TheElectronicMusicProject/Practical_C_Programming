#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char ** argv)
{
    char    line[100] = { 0 };
    int     num = 0;

    while (1)
    {
        printf("Butta un numero: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &num);

        do
        {
            printf("num = %d\n", num);
            ++num;
        } while (num <= 10);

        if (num == 11)
        {
            goto end;
        }
        else
        {
            goto ok;
        }
ok:
        printf("Si continua\n");
    }

end:
    printf("Esco");

    return (0);
}