#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *input;
FILE *out1;
FILE *out2;
char line[100];

int main(void){
	unsigned long int buf;
	char temp[100];
	int ch;
	int i = 0, j = 0;
	int p;
	unsigned long int temporary_number;
	printf("Insert input file: ");
	fgets(line, sizeof(line), stdin);
	while(*(line + i) != '\n')
		++i;
	line[i] = '\0';
	input = fopen(line, "r");
	if(input == NULL){
		fprintf(stderr, "Errore in aprire %s", line);
		exit(8);
	}
	out1 = fopen("three.txt", "a");
	if(out1 == NULL){
		fprintf(stderr, "Errore in aprire %s", "three.txt");
		exit(8);
	}
	out2 = fopen("other.txt", "a");
	if(out2 == NULL){
		fprintf(stderr, "Errore in aprire %s", "other.txt");
		exit(8);
	}
	do{
		fscanf(input, "%d", &buf);
		if(buf % 3 == 0){
			i = 0;
			while(temp[i] != '\0'){
				fprintf(out1, "%c", temp[i]);
				++i;
			}
			fprintf(out1, "\n");
		}
		else if(buf % 3 != 0){
			i = 0;
			while(temp[i] != '\0'){
				fprintf(out2, "%c", temp[i]);
				++i;
			}
			fprintf(out2, "\n");
		}
	}while(ch != EOF);
	fclose(input);
	fclose(out1);
	fclose(out2);
	return (0);
}