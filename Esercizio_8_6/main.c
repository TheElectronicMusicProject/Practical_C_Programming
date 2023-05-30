#include <stdio.h>

#define SIZE 100

char line[SIZE];
int i = 0;

int main(void){
	while(1){
		i = 0;
		printf("Insert a number: ");
		fgets(line, sizeof(line), stdin);
		for(i = 0; line[i] != '\n'; ++i){
			switch(line[i]){
				case '0':
					printf("zero ");
					break;
				case '1':
					printf("one ");
					break;
				case '2':
					printf("two ");
					break;
				case '3':
					printf("three ");
					break;
				case '4':
					printf("four ");
					break;
				case '5':
					printf("five ");
					break;
				case '6':
					printf("six ");
					break;
				case '7':
					printf("seven ");
					break;
				case '8':
					printf("eight ");
					break;
				case '9':
					printf("nine ");
					break;
				default:
					printf("Not a number.\n");
					line[i] = '\n';
					break;
			}
		}
		printf("\n");
	}
	return (0);
}