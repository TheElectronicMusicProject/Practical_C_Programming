#include <stdio.h>

float miles;
float km;
const float constant = 0.6213712;
char strings[20];

int main(void){
	printf("km: ");
	fgets(strings, sizeof(strings), stdin);
	sscanf(strings, "%f", &km);
	miles = constant * km;
	printf("miles: %f", miles);
	return (0);
}