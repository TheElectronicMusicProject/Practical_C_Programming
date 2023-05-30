#include <stdio.h>
#include <string.h>

#define NUM_LIST    3

struct time
{
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct flight
{
    long int number;
    char orig_code[4];
    char dest_code[4];
    struct time start;
    struct time arrive;
};

static void
print_flight (struct flight fligth_list[], int elements)
{
    int idx = 0;

    while (idx < elements)
    {
        printf("STAMPO #%d\n", idx + 1);
        printf("Numero: %ld\n", fligth_list[idx].number);
        printf("Codice di partenza: %s\n", fligth_list[idx].orig_code);
        printf("Codice di destinazione: %s\n", fligth_list[idx].dest_code);
        printf("Partenza: %d/%d/%d\t%d:%d\n", fligth_list[idx].start.day,
               fligth_list[idx].start.month, fligth_list[idx].start.year,
               fligth_list[idx].start.hour, fligth_list[idx].start.minute);
        printf("Arrivo: %d/%d/%d\t%d:%d\n", fligth_list[idx].arrive.day,
               fligth_list[idx].arrive.month, fligth_list[idx].arrive.year,
               fligth_list[idx].arrive.hour, fligth_list[idx].arrive.minute);

        ++idx;
    }

    return;
}

int
main (void)
{
    int             idx = 0;
    int             field = 0;
    char            line[60] = { 0 };
    struct flight   list[NUM_LIST] = { 0 };
    
    while (idx < NUM_LIST)
    {
        printf("#%d\n", idx + 1);

        for (field = 0; field < 5; ++field)
        {
            switch (field)
            {
                case 0:
                    printf("Numero: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%ld", &list[idx].number);
                break;

                case 1:
                    printf("Codice partenza: ");
                    fgets(line, sizeof(line), stdin);
                    line[strlen(line) - 1] = '\0';
                    strcpy(list[idx].orig_code, line);
                break;

                case 2:
                    printf("Codice arrivo: ");
                    fgets(line, sizeof(line), stdin);
                    line[strlen(line) - 1] = '\0';
                    strcpy(list[idx].orig_code, line);
                break;

                case 3:
                    printf("Partenza: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%d/%d/%d %d:%d", &list[idx].start.day,
                           &list[idx].start.month, &list[idx].start.year,
                           &list[idx].start.hour, &list[idx].start.minute);
                break;

                case 4:
                    printf("Arrivo: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%d/%d/%d %d:%d", &list[idx].arrive.day,
                           &list[idx].arrive.month, &list[idx].arrive.year,
                           &list[idx].arrive.hour, &list[idx].arrive.minute);
                break;

                default:
                    printf("ERROR\n");
                break;
            }
        }

        ++idx;
    }

    print_flight(list, NUM_LIST);

    return (0);
}