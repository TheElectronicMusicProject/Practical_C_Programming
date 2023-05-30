#include <stdio.h>

char ch;

int main(void){
	FILE *input = fopen("in.txt", "r");
	FILE *output = fopen("out.txt", "a");
	do{
		ch = fgetc(input);
		if((ch & 0x80) == 0){
			fputc(ch, output);
		}
	}while(ch != EOF);
	fclose(input);
	fclose(output);
	return (0);
}