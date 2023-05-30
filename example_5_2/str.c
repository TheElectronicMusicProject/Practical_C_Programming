#include <string.h>
#include <stdio.h>

int
main (void)
{
    char name[30] = "Gigio";
    char eheh[] = "ano";
    int len = 0;

    strcpy(name, "Sam");

    len = strlen(name);
    printf("lunghezza = %d\n", len);

    strcat(name, eheh);
    len = strlen(name);
    printf("lunghezza = %d\n", len);

    printf("The name is %s\n", name);

    if (0 == strcmp(name, "Samano"))
    {
        printf("burlone!");
    }

    return (0);
}