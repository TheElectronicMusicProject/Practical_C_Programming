#include <stdio.h>

#define X_SIZE 48
#define Y_SIZE 48

char graphics[X_SIZE / 8][Y_SIZE];

#define SET_BIT(x,y)    (graphics[(x) / 8][y] |= (0x80 >> ((x) % 8)))

int
main (void)
{
    int loc;
    void print_graphics(void);

    for (loc = 0; loc < X_SIZE; ++loc)
    {
        SET_BIT(loc, loc);
    }

    print_graphics();

    return (0);
}

void
print_graphics (void)
{
    int             x;
    int             y;
    unsigned int    bit;

    for (y = 0; y < Y_SIZE; ++y)
    {
        for (x = 0; x < (X_SIZE / 8); ++x)
        {
            for (bit = 0x80; bit > 0; bit >>= 1)
            {
                if (0 != (graphics[x][y] & bit))
                {
                    printf("X ");
                }
                else
                {
                    printf(". ");
                }
            }
        }

        printf("\n");
    }

    return;
}