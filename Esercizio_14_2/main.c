#include <stdio.h>
#include <stdlib.h>

FILE *in_file;
FILE *out_file;
char title[] = "text.txt";
char title2[] = "out.txt";

int main(void){
	int i = 0;
	int ch;
	in_file = fopen(title, "r");
	if(in_file == NULL){
		fprintf(stderr, "Errore in apertura file %s", title);
		exit(8);
	}
	out_file = fopen(title2, "a");
	if(out_file == NULL){
		fprintf(stderr, "Errore in apertura file %s", title2);
		exit(8);
	}
	do{
		ch = fgetc(in_file);
		if(ch == '\t'){
			for(i = 0; i < 4; ++i){
				fprintf(out_file, " ");
			}
		}
		else
			fprintf(out_file, "%c", (char)ch);
	}while(ch != EOF);
	if(fclose(in_file)){
		fprintf(stderr, "Errore in chiusura file %s", title);
		exit(8);
	}
	if(fclose(out_file)){
		fprintf(stderr, "Errore in chiusura file %s", title2);
		exit(8);
	}
	printf("DONE!");
	return (0);
}