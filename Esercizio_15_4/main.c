#include <stdio.h>
#include <string.h>
#include <time.h>

char line[300];
int i = 0;

int main(void){
	register unsigned int tot = 0;
	clock_t start, end;
	printf("Inserire stringa: ");
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';
	start = clock();
	for(i = 0; *(line + i) != '\0'; ++i){
		++tot;
	}
	tot *= 8;
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("In questa stringa ci sono %u bit, in un tempo %f.", tot, time);
	return (0);
}