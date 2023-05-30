#include <stdio.h>
#include <string.h>

int
main (void)
{
    int hour = 0;
    int minute = 0;
    int tot_minutes = 0;
    char buffer[100] = { 0 };

    printf("Inserire minuti: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%d", &tot_minutes);

    hour = tot_minutes / 60;
    minute = tot_minutes - (60 * hour);

    if ((hour == 1) && (minute == 1))
    {
        printf("%d ora e %d minuto", hour, minute);
    }
    else if ((hour != 1) && (minute == 1))
    {
        printf("%d ore e %d minuto", hour, minute);
    }
    else if ((hour == 1) && (minute != 1))
    {
        printf("%d ora e %d minuti", hour, minute);
    }
    else
    {
        printf("%d ore e %d minuti", hour, minute);
    }

    return (0);
}