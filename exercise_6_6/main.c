#include <stdio.h>

int
main (int argc, char ** argv)
{
    char        line[100] = { 0 };
    double      hours = 0.0;
    double      money_per_hour = 0.0;
    double      diff_hour = 0.0;
    const int   hours_per_week = 40;
    double      total_pay = 0.0;

    while (1)
    {
        printf("Inserire le ore lavorate nella settimana e la paga oraria: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%lf %lf", &hours, &money_per_hour);

        if (hours < 0)
        {
            break;
        }

        diff_hour = hours - hours_per_week;
        printf("diff = %f", diff_hour);

        if (diff_hour > 0)
        {
            total_pay = money_per_hour * hours_per_week + 1.5 * money_per_hour * diff_hour;
        }
        else
        {
            total_pay = money_per_hour * hours;
        }
        
        printf("Paga settimanale %f\n", total_pay);
    }
    
    return (0);
}