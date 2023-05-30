#include <stdio.h>
#include <string.h>

int
main (void)
{
    float radius = 0.0;
    float fahrenheit = 0.0;
    char buffer[100] = { 0 };
    const float pi = 3.141;

    printf("Inserire raggio[m]: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%f", &radius);

    fahrenheit = 4 * pi / 3 * radius * radius * radius;

    printf("Gradi fahrenheit = %f\n", fahrenheit);

    return (0);
}