#include <stdio.h>

unsigned long int hash_code = 0;
char line[100];

unsigned long int hash_gen(char string[]);

int main(void){
	printf("Insert some characters: ");
	fgets(line, sizeof(line), stdin);
	hash_code = hash_gen(line);
	printf("Result: %lu", hash_code);
	return (0);
}

unsigned long int hash_gen(char string[]){
	int i = 0;
	unsigned long int result = 0;
	for(i = 0; string[i] != '\n'; ++i){
		result += string[i];
	}
	return result;
}