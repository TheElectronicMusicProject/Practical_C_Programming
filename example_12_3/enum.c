#include <stdio.h>

enum week_day
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
};

int
main (void)
{
    enum week_day today = SUNDAY;

    printf("Today is %d\n", today);

    today = 5;

    printf("Today is %d\n", today);

    return (0);
}