#include <stdio.h>
#include <string.h>

int
main (void)
{
    float celsius = 0.0;
    float fahrenheit = 0.0;
    char buffer[100] = { 0 };

    printf("Inserire gradi celsius: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%f", &celsius);

    fahrenheit = 9 * celsius / 5 + 32;

    printf("Gradi fahrenheit = %f\n", fahrenheit);

    return (0);
}