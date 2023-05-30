#include <stdio.h>
#include <string.h>

int
main (void)
{
    float miles = 0.0;
    float kilometers = 0.0;
    char buffer[100] = { 0 };
    const float conv = 0.6213712;

    printf("Inserire larghezza e altezza [m]: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%f", &kilometers);

    miles = conv * kilometers;

    printf("miles per hour = %f\n", miles);

    return (0);
}