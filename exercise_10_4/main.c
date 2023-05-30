#include <stdio.h>

#define SWAP(a, b)      {               \
                            a ^= b;     \
                            b^= a;      \
                            a ^= b;     \
                        }


int
main (int argc, char * argv[])
{
    int num1, num2;
    char line[100] = { 0 };

    while (1)
    {
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d %d", &num1, &num2);

        printf("You put a = %d, b = %d\n", num1, num2);
        
        SWAP(num1, num2);

        printf("You have a = %d, b = %d\n", num1, num2);
    }

    return (0);
}