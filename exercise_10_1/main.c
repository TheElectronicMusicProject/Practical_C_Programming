#include <stdio.h>

#define FALSE   0
#define TRUE    1
#define DIV_10(input)   (((input % 10) == 0) ? TRUE : FALSE)


int
main (int argc, char * argv[])
{
    int i = 0;
    for (i = 0; i < 101; ++i)
    {
        if (TRUE == DIV_10(i))
        {
            printf("%d e' divisibile per 10\n", i);
        }
        else
        {
            printf("%d no\n", i);
        }
    }

    return (0);
}