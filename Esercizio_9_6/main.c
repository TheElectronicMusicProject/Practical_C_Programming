#include <stdio.h>

char input[100];
void converter(char string[]);

int main(void){
	printf("Insert some characters with some -: ");
	fgets(input, sizeof(input), stdin);
	converter(input);
	printf("%s\n", input);
	return (0);
}

void converter(char string[]){
	int i;
	for(i = 0; string[i] != '\n'; ++i){
		if(string[i] == '-'){
			string[i] = '_';
		}
		if(string[i] == '\n'){
			string[i] = '\0';
		}
	}
	string[i] = '\0';
}