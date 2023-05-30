#include <stdio.h>

#define X_SIZE 16
#define Y_SIZE 16

char graphics[X_SIZE / 8][Y_SIZE];

#define SET_BIT(x,y)    (graphics[(x) / 8][y] |= (0x80 >> ((x) % 8)))

int
main (void)
{
    int x_loc;
    int y_loc;
    void print_graphics(void);

    for (y_loc = 0; y_loc < Y_SIZE; ++y_loc)
    {
        for (x_loc = 0; x_loc < X_SIZE; ++x_loc)
        {
            if (((0 == y_loc % 9) || (0 == x_loc % 9)) && (x_loc < 10) && (y_loc < 10))
            {
                SET_BIT(x_loc, y_loc);
            }
        }

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