#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main (int argc, char * argv[])
{
    const float sales_per_cent = 8.0;
    double      product_cost = 0.0;
    int         temp_penny = 0;
    char        line[100] = { 0 };

    while (1)
    {
        printf("Insert product cost:\t");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%lf", &product_cost);

        product_cost += product_cost * (double) sales_per_cent / 100.0;
#if 0
        printf("## product_cost read = %lf\n", product_cost);
#endif
        product_cost *= 100;

        product_cost = round(product_cost) / 100;

        printf("Cost + taxes = %lf\n", product_cost);
    }

    return (0);
}