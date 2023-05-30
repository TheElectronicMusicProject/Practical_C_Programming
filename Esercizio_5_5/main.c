#include <stdio.h>

unsigned short int hours;
unsigned short int minutes;
unsigned int total = 0;
char strings[20];

int main(void){
	printf("ore minuti: ");
	fgets(strings, sizeof(strings), stdin);
	sscanf(strings, "%hu %hu", &hours, &minutes);
	total = minutes + hours * 60;
	printf("minuti totali: %u", total);
	return (0);
}