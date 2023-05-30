#include <stdio.h>

char line[100];
long int number;
char vect[sizeof(long int) * 8 / 4];

int main(void){
	printf("Number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%ld", &number);
	int i = 0;
	for(i = 0; i < sizeof(long int) * 8 / 4; ++i){
		vect[i] = number & 0x0000000F;
		if((number & 0x80000000) != 0){
			printf("## dopo if");
			number &= ~0x80000000;
			number = number >> 4;
			number |= ~0x08000000;
		}
		else{
			number = number >> 4;
		}
		printf("Pezzo %d e' %d\n", i, vect[i]);
	}
	return (0);
}