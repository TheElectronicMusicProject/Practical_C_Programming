#include <stdio.h>
#include <stdlib.h>

char num = 0;

int main(void){
	FILE *input = fopen("in.txt", "r");								// Apri file ASCII
	if(input == NULL){
		fprintf(stderr, "Errore in apertura di %s", "in.txt");
		exit(8);
	}
	FILE *output = fopen("out.bin", "ab");							// Apri o crea file binario
	if(output == NULL){
		fprintf(stderr, "Errore in apertura di %s", "out.bin");
		exit(8);
	}
	while(fscanf(input, "%c", &num) != EOF){						// Leggi file ASCII
		printf("## num e': %d\n", num);
		if(fwrite(&num, 1, sizeof(num), output) != sizeof(num)){	// Scrivi file binario
			fprintf(stderr, "Errore in scrittura");
			exit(8);
		}
	}
	printf("FINE");
	fflush(stdout);													// Svuotamento buffer
	fclose(input);
	fclose(output);
	return (0);
}