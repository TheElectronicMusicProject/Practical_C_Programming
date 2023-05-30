#include <stdio.h>

union value
{
    long int i_value;
    float f_value;
} data;

int i;
float f;

int
main (void)
{
    data.f_value = 5.1;
    data.i_value = 3;

    i = data.i_value;
    f = data.f_value;
    
    printf("i = %d, f = %f\n", i, f);

    data.f_value = 5.5;

    i = data.i_value;

    printf("i = %d\n", i);

    printf("i_value = %ld, f_value = %f\n", data.i_value, data.f_value);

    return (0);
}