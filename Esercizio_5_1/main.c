#include <stdio.h>

float degrees = 0, fahrenheit = 0;
char stringa[20];

int main(void){
	printf("Insert degrees to convert: ");
	fgets(stringa, sizeof(stringa), stdin);
	sscanf(stringa, "%f", &degrees);
	fahrenheit = 9.0 * degrees / 5.0 + 32;
	printf("%f degrees are %f fahrenheit", degrees, fahrenheit);
	return(0);
}