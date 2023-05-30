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
		buf = 0;
		i = 0;
		j = 0;
		do{
			temp[i] = ch = getc(input);
			if((char)ch == '0' || (char)ch == '1' || (char)ch == '2' || (char)ch == '3' ||
			(char)ch == '4' || (char)ch == '5' || (char)ch == '6' || (char)ch == '7' ||
			(char)ch == '8' || (char)ch == '9'){
				++i;
				//buf += (ch - '0') * pow(10, i);
			}
		}while(ch != EOF && ch != '\t' && ch != ' ' && ch != '\n' && ch != '\0');
		temp[i] = '\0';
		while(i - 1 - j >= 0 && i != 0){
			temporary_number = 1;
			for(p = i - 1 - j; p > 0; --p){
				temporary_number *= 10;
			}
			/*printf("## index = %d\n", i - 1 - j);
			printf("## temporary = %lu\n", temporary_number);*/
			buf += (temp[j] - '0') * temporary_number;
			/*printf("## temp buf = %d\n", temp[j] - '0');
			printf("## pow = %f\n", pow(10, i - 1 - j));
			printf("## buf = %lu\n", (temp[j] - '0') * (unsigned long int)pow(10, i - 1 - j));*/
			++j;
		}
		printf("## buf = %lu\t", buf);
		printf("## temp = %s\n", temp);
		if(buf % 3 == 0 && i != 0){
			i = 0;
			while(temp[i] != '\0'){
				fprintf(out1, "%c", temp[i]);
				++i;
			}
			fprintf(out1, "\n");
		}
		else if(buf % 3 != 0 && i != 0){
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