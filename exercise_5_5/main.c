#include <stdio.h>
#include <string.h>

int
main (void)
{
    int hour = 0;
    int minute = 0;
    int tot_minutes = 0;
    char buffer[100] = { 0 };

    printf("Inserire ore e minuti: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%d %d", &hour, &minute);

    tot_minutes = 60 * hour + minute;

    if (tot_minutes == 1)
    {
        printf("%d minuto", tot_minutes);
    }
    else
    {
        printf("%d minuti", tot_minutes);
    }

    return (0);
}