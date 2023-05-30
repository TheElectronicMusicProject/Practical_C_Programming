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

static void
print_fl (struct flight fligth)
{
    printf("Numero: %ld\n", fligth.number);
    printf("Codice di partenza: %s\n", fligth.orig_code);
    printf("Codice di destinazione: %s\n", fligth.dest_code);
    printf("Partenza: %d/%d/%d\t%d:%d\n", fligth.start.day,
            fligth.start.month, fligth.start.year,
            fligth.start.hour, fligth.start.minute);
    printf("Arrivo: %d/%d/%d\t%d:%d\n", fligth.arrive.day,
            fligth.arrive.month, fligth.arrive.year,
            fligth.arrive.hour, fligth.arrive.minute);

    return;
}

int
main (void)
{
    int             idx = 0;
    char            airpor1[4];
    char            airpor2[4];
    char            line[60] = { 0 };
    struct flight   list[NUM_LIST] = { 0 };

    list[0].number = 48018;
    strcpy(list[0].orig_code, "112");
    strcpy(list[0].dest_code, "113");
    list[0].start.day = 14;
    list[0].start.month = 8;
    list[0].start.year = 2022;
    list[0].start.hour = 10;
    list[0].start.minute = 30;
    list[0].arrive.day = 14;
    list[0].arrive.month = 8;
    list[0].arrive.year = 2022;
    list[0].arrive.hour = 15;
    list[0].arrive.minute = 50;

    list[1].number = 48019;
    strcpy(list[1].orig_code, "113");
    strcpy(list[1].dest_code, "115");
    list[1].start.day = 12;
    list[1].start.month = 6;
    list[1].start.year = 2022;
    list[1].start.hour = 13;
    list[1].start.minute = 26;
    list[1].arrive.day = 12;
    list[1].arrive.month = 6;
    list[1].arrive.year = 2022;
    list[1].arrive.hour = 14;
    list[1].arrive.minute = 58;

    list[2].number = 413112;
    strcpy(list[2].orig_code, "112");
    strcpy(list[2].dest_code, "635");
    list[2].start.day = 9;
    list[2].start.month = 10;
    list[2].start.year = 2022;
    list[2].start.hour = 3;
    list[2].start.minute = 45;
    list[2].arrive.day = 9;
    list[2].arrive.month = 10;
    list[2].arrive.year = 2022;
    list[2].arrive.hour = 20;
    list[2].arrive.minute = 16;

    print_flight(list, NUM_LIST);

    while (1)
    {
        printf("Inserire due codici volo\n");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%s %s", airpor1, airpor2);

        for (idx = 0; idx < NUM_LIST; ++idx)
        {
            if ((0 == strcmp(list[idx].orig_code, airpor1)) ||
                (0 == strcmp(list[idx].orig_code, airpor2)))
            {
                print_fl(list[idx]);
            }
        }
    }

    return (0);
}