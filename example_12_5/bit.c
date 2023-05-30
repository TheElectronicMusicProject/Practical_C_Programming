#include <stdio.h>

struct item
{
    unsigned int list:1;
    unsigned int seen:1;
    unsigned int number:14;
};

int
main (void)
{
    struct item new_item;

    new_item.list = 0;
    new_item.seen = 1;
    new_item.number = 0xFFE;

    printf("%d, %d, %d\n", new_item.list, new_item.seen, new_item.number);

    return (0);
}