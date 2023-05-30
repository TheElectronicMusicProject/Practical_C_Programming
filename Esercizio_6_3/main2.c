#include <stdio.h>
#include <string.h>

char string[10];
int num_val = 0;
char let_val;
char sym_val;
int i;

int main(void){
	while(1) {
		printf("Insert a numerical grade: ");
		fgets(string, sizeof(string), stdin);
		sscanf(string, "%d", &num_val);
		if(0 <= num_val && 60 >= num_val){
			let_val = 'F';
		} else if (61 <= num_val && 70 >= num_val){
			let_val = 'D';
		} else if (71 <= num_val && 80 >= num_val){
			let_val = 'C';
		} else if (81 <= num_val && 90 >= num_val){
			let_val = 'B';
		} else if (91 <= num_val && 100 >= num_val){
			let_val = 'A';
		} else {
			printf("Invalid number");
			break;
		}
		i = 0;
		if(let_val != 'F'){
			while(string[i] != '\n')
				++i;
			if('1' <= string[i - 1] && '3' >= string[i - 1])
				sym_val = '-';
			else if('4' <= string[i - 1] && '7' >= string[i - 1])
				sym_val = ' ';
			else if(('8' <= string[i - 1] && '9' >= string[i - 1]) || '0' == string[i - 1])
				sym_val = '+';
		} else {
			sym_val = ' ';
		}
		printf("Letter grade: %c%c\n", let_val, sym_val);
	}
	return 0;
}