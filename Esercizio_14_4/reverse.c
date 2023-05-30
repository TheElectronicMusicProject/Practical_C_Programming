#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024 * 16

unsigned char buffer[SIZE];
int i = 0;

int main(void){
	FILE *input = fopen("out.bin", "rb");							// Apri file binario
	if(input == NULL){
		fprintf(stderr, "Errore in apertura di %s", "out.bin");
		exit(8);
	}
	FILE *output = fopen("reverse.txt", "a");						// Apri o crea file ASCII
	if(output == NULL){
		fprintf(stderr, "Errore in apertura di %s", "reverse.txt");
		exit(8);
	}
	fread(buffer, 1, sizeof(buffer), input);						// Leggi file binario
	while(buffer[i] != '\0'){
		printf("## num e': %d\n", buffer[i]);
		fflush(stdout);
		if(buffer[i] != '\n'){
			fprintf(output, "%c", buffer[i]);
		}
		else{
			fprintf(output, "\n");
		}
		++i;
	}									// Scrivi file ASCII
	printf("FINE");
	fflush(stdout);													// Svuotamento buffer
	fclose(input);
	fclose(output);
	return (0);
}