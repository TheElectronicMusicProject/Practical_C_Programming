#include <stdio.h>

unsigned int words = 0;
char line[100];

int main(void){
	while(1){
		int i = 0;
		words = 1;
		printf("Insert some words: ");
		fgets(line, sizeof(line), stdin);
		for(i = 0; line[i] != '\n'; ++i){
			if(line[i] == ' '){
				++words;
			}
		}
		printf("There are %u words\n", words);
	}
	return 0;
}