#include <stdio.h>
#include <string.h>

int
main (void)
{
    float perimeter = 0.0;
    float width = 0.0;
    float height = 0.0;
    char buffer[100] = { 0 };

    printf("Inserire larghezza e altezza [m]: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%f %f", &width, &height);

    perimeter = 2 * (width + height);

    printf("perimeter = %f\n", perimeter);

    return (0);
}