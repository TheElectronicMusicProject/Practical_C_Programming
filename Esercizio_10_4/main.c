#include <stdio.h>

#ifndef MACRO
#define MACRO
#define SWAP(n1, n2)	{				\
						n2 ^= n1;		\
						n1 ^= n2;		\
						n2 ^= n1;		\
						}
#endif /* MACRO */

char line[100];
int number1, number2;

int main(void){
	printf("Insert a number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &number1);
	
	printf("Insert a number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &number2);
	
	printf("First number: %d\nFirst number: %d\n\n", number1, number2);
	SWAP(number1, number2);
	printf("First number: %d\nFirst number: %d\n\n", number1, number2);
	return (0);
}