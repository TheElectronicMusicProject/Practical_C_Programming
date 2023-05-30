#include <stdio.h>
#include <stdlib.h>

FILE *input_file;
char line[100];
int count = 0;

int main(void){
	int i = 0;
	int ch;
	printf("Insert the name of the file: ");
	fgets(line, sizeof(line), stdin);
	while(*(line + i) != '\n')
		++i;
	*(line + i) = '\0';
	input_file = fopen(line, "r");
	if(input_file == NULL){
		fprintf(stderr, "Non posso aprire il file\n");
		exit(8);
	}
	i = 0;
	do{
		ch = fgetc(input_file);
		if(ch == '\n')
			++i;
	}while(ch != EOF);
	++i;
	fclose(input_file);
	printf("Number of lines in %s is %d", line, i);
	return (0);
}