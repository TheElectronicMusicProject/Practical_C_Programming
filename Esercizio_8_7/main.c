#include <stdio.h>

#define SIZE 100

void unit(char input);
void decimal(char input2, char input1);

char line[SIZE];
int i = 0, j = 0;

int main(void){
	while(1){
		i = 0;
		j = 0;
		printf("Insert a number: ");
		fgets(line, sizeof(line), stdin);
		for(j = 0; line[j] != '\n'; ++j);
		if(j == 1){
			unit(line[0]);
		}
		else if(j == 2){
			decimal(line[0], line[1]);
		}
		else if(j == 3){
			printf("one hundred ");
		}
		else
			printf("Number not valid!");
		printf("\n");
	}
	return (0);
}

void decimal(char input2, char input1){
	switch(input2){
		case '1':
			switch(input1){
				case '0':
					printf("ten ");
					break;
				case '1':
					printf("eleven ");
					break;
				case '2':
					printf("twelve ");
					break;
				case '3':
					printf("thirteen ");
					break;
				case '4':
					printf("fourteen ");
					break;
				case '5':
					printf("fifteen ");
					break;
				case '6':
					printf("sixteen ");
					break;
				case '7':
					printf("seventeen ");
					break;
				case '8':
					printf("eighteen ");
					break;
				case '9':
					printf("nineteen ");
					break;
			}
			break;
		case '2':
			printf("twenty ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '3':
			printf("thirty ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '4':
			printf("fourty ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '5':
			printf("fifty ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '6':
			printf("sixty ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '7':
			printf("seventy ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '8':
			printf("eighty ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		case '9':
			printf("ninety ");
			if(input1 != '0'){
				unit(input1);
			}
			break;
		default:
			printf("Not a number.\n");
			line[i] = '\n';
			break;
	}
	return;
}

void unit(char input){
	switch(input){
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
	return;
}