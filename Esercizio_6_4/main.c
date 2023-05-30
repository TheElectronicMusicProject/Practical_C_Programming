#include <stdio.h>

char line[10];
int money;
int fifty = 0;
int twenty = 0;
int ten = 0;
int five = 0;
int two = 0;
int one = 0;

int main(void){
	printf("Insert a money value (< 1.00): ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%u", &money);
	while(money / 50 != 0){
		money -= 50;
		++fifty;
	}
	while(money / 20 != 0){
		money -= 20;
		++twenty;

	}
	while(money / 10 != 0){
		money -= 10;
		++ten;
	}
	while(money / 5 != 0){
		money -= 5;
		++five;
	}
	while(money / 2 != 0){
		money -= 2;
		++two;
	}
	while(money / 1 != 0){
		money -= 1;
		++one;
	}
	printf("%d pezzi da 50, %d pezzi da 20, %d pezzi da 10, %d pezzi da 5, %d pezzi da 2, %d pezzi da 1", fifty, twenty, ten, five, two, one);
	return 0;
}