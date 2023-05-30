#include <stdio.h>

char line[100];
int number;
unsigned int pos_n = 0;
unsigned int neg_n = 0;

int main(void){
	while(1){
		printf("Insert a number: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &number);
		if(number == 0)
			break;
		(number > 0) ? (++pos_n) : (++neg_n);
	}
	printf("%d positive numbers and %d negative numbers", pos_n, neg_n);
	return 0;
}