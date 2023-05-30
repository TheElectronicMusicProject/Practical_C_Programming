#include <stdio.h>

unsigned int counter_ones(unsigned int number);

char line[100];
unsigned int number = 0;

int main(void){
	printf("Inserisci numero: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%u", &number);
	printf("Numero di bit a 1 in %u e' %u", number, counter_ones(number));
	return (0);
}

unsigned int counter_ones(unsigned int number){
	int i = 0;
	unsigned int value = 0;
	for(i = 0; i < sizeof(unsigned int) * 8; ++i){
		if(number >> i & 1)
			value++;
	}
	return value;
}