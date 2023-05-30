#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *input;
FILE *out1;
FILE *out2;
char line[100];

int main(void){
	unsigned long int buf;
	int i = 0;
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
	while(fscanf(input, "%lu", &buf) != EOF){
		//printf("## buf %lu\n", buf);
		if(buf % 3 == 0){
			fprintf(out1, "%lu\n", buf);
		}
		else if(buf % 3 != 0){
			fprintf(out2, "%lu\n", buf);
		}
	}
	fclose(input);
	fclose(out1);
	fclose(out2);
	return (0);
}