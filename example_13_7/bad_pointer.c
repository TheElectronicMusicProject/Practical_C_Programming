#include <stdio.h>

int
main (void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value;
    int * data_ptr;

    printf("#0 %d\n", array[0]);

    data_ptr = &array[0];
    value = *data_ptr++;
    printf("#1 %d\n", value);

    data_ptr = &array[0];
    value = *++data_ptr;
    printf("#2 %d\n", value);

    data_ptr = &array[0];
    value = ++*data_ptr;
    printf("#3 %d\n", value);

    return (0);
}