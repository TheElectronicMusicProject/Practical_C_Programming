#include <stdio.h>

char line[100];
unsigned int number;
int i = 0;

int main(void){
	while(1){
		printf("Insert a number: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%u", &number);
		i = 2;
		if(number == 0)
			break;
		if(number == 1)
			printf("%d is prime\n", number);
		else{
			while(i <= number - 1){
				if(number % i == 0)
					break;
				//printf("%d \t %d\n", i, number % i);
				++i;
			}
			if(i == number)
				printf("%d is prime\n", number);
			else
				printf("%d is not prime\n", number);
		}
	}
	return 0;
}