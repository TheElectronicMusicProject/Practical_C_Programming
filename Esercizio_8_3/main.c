#include <stdio.h>

float input;
double total = 0;
int iterations;
char line[100];

int main(void){
	while(1){
		printf("Insert number: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%f", &input);
		if(input >= 0){
			total += input;
		}
		else{
			break;
		}
		++iterations;
	}
	printf("Average of %d is: %f", iterations, total/iterations);
	return 0;
}