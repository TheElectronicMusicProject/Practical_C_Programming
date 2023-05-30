#include <stdio.h>
#include <string.h>

#define NUM_LIST    3

typedef struct mailing
{
    char name[60];
    char address1[60];
    char address2[60];
    char city[40];
    char state[2];
    long int zip;
} mailing_t;

static void
print_mail (mailing_t mail_list[NUM_LIST])
{
    int idx = 0;

    while (idx < NUM_LIST)
    {
        printf("STAMPO #%d\n", idx + 1);
        printf("Nome: %s\n", mail_list[idx].name);
        printf("Indirizzo 1: %s\n", mail_list[idx].address1);
        printf("Indirizzo 2: %s\n", mail_list[idx].address2);
        printf("Citta': %s\n", mail_list[idx].city);
        printf("Stato: %c %c\n", mail_list[idx].state[0], mail_list[idx].state[1]);
        printf("CAP: %ld\n", mail_list[idx].zip);

        ++idx;
    }

    return;
}

int
main (void)
{
    int         idx = 0;
    int         field = 0;
    char        line[60] = { 0 };
    mailing_t   list[NUM_LIST] = { 0 };
    
    while (idx < NUM_LIST)
    {
        printf("#%d\n", idx + 1);

        for (field = 0; field < 6; ++field)
        {
            switch (field)
            {
                case 0:
                    printf("Nome: ");
                    fgets(line, sizeof(line), stdin);
                    line[strlen(line) - 1] = '\0';
                    strcpy(list[idx].name, line);
                break;

                case 1:
                    printf("Indirizzo 1: ");
                    fgets(line, sizeof(line), stdin);
                    line[strlen(line) - 1] = '\0';
                    strcpy(list[idx].address1, line);
                break;

                case 2:
                    printf("Indirizzo 2: ");
                    fgets(line, sizeof(line), stdin);
                    line[strlen(line) - 1] = '\0';
                    strcpy(list[idx].address2, line);
                break;

                case 3:
                    printf("Citta': ");
                    fgets(line, sizeof(line), stdin);
                    line[strlen(line) - 1] = '\0';
                    strcpy(list[idx].city, line);
                break;

                case 4:
                    printf("Stato: ");
                    fgets(line, sizeof(line), stdin);
                    list[idx].state[0] = line[0];
                    list[idx].state[1] = line[1];
                break;

                case 5:
                    printf("CAP: ");
                    fgets(line, sizeof(line), stdin);
                    sscanf(line, "%ld", &list[idx].zip);
                break;

                default:
                    printf("ERROR\n");
                break;
            }
        }

        ++idx;
    }

    print_mail(list);

    return (0);
}