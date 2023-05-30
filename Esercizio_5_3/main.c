#include <stdio.h>

float width;
float height;
float perimeter;
char strings[20];

int main(void){
	printf("Width height: ");
	fgets(strings, sizeof(strings), stdin);
	sscanf(strings, "%f %f", &width, &height);
	perimeter = 2 * (width + height);
	printf("Perimeter: %f", perimeter);
	return (0);
}