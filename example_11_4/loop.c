#include <stdio.h>

int
main (void)
{
    short int i;
    signed char ch;

    for (i = 0x80; i != 0; i = (i >> 1))
    {
        printf("i is %x (%d)\n", i , i);
    }

    for (ch = 0x80; ch != 0; ch = (ch >> 1))
    {
        printf("ch is %x (%d)\n", ch , ch);
    }

    return (0);
}