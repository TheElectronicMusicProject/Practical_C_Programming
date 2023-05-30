#include <stdio.h>
#include <math.h>

char line[100];
int amount = 0;
int result = 0;

int main(void){
	while(1){
		printf("Insert the amount: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &amount);
		if(amount < 0)
			break;
		float temp = amount + amount * 8.0 / 100.0;
		result = round(temp);
		printf("Rounded amount with sales tax: %d\n", result);
	}
	return 0;
}