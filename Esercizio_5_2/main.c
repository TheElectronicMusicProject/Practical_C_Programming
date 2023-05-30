#include <stdio.h>

const float PI = 3.141;
int radius = 0;
char string[10];
double volumed;
double volumef;

int main(void){
	printf("Insert radius: ");
	fgets(string, sizeof(string), stdin);
	sscanf(string, "%d", &radius);
	volumed = 4 * PI * radius * radius / 3.0;
	volumef = 4 * PI * radius * radius / 3.0;
	printf("Double is %f and float is %f", volumed, volumef);
	return 0;
}