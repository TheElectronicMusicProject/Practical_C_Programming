#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define sum(x, y)		((x) + (y))
#define mul(x, y)		((x) * (y))
#define sub(x, y)		((x) - (y))
#define div(x, y)		((x) / (y))

char line[10];
int q1, q2;
float n1, n2, out;
int i = 0;

int main(void){
	printf("Enter format of int: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d.%d", &q1, &q2);
	printf("Enter first number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &n1);
	printf("Enter second number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &n2);
	if((q1 + q2) / 8 != sizeof(short int)){
		fprintf(stderr, "Wrong immission, in is %d byte", sizeof(int));
		exit(8);
	}
	int power = (int)pow(2, q2);
	int n1_fix = n1 * power;
	int n2_fix = n2 * power;
	printf("n1 = %f, n1_fix = %d, parte intera = %d.%d\n", n1, n1_fix, n1_fix >> q2, n1_fix % q2);
	printf("n2 = %f, n2_fix = %d, parte intera = %d.%d\n", n2, n2_fix, n2_fix >> q2, n2_fix % q2);
	
	printf("Somma = %f, Somma virgola fissa = %d.%d\n", sum(n1, n2), sum(n1_fix, n2_fix) >> q2, sum(n1_fix, n2_fix) % q2);
	printf("Prodotto = %f, Prodotto virgola fissa = %d.%d\n", mul(n1, n2), mul(n1_fix >> q2, n2_fix >> q2), mul(n1_fix % q2, n2_fix % q2));
	printf("Divisione = %f, Divisione virgola fissa = %d.%d\n", div(n1, n2), div(n1_fix, n2_fix) >> q2, div(n1_fix, n2_fix) % q2);
	printf("Sottrazione = %f, Sottrazione virgola fissa = %d.%d\n", sub(n1, n2), sub(n1_fix, n2_fix) >> q2, sub(n1_fix, n2_fix) % q2);
	return (0);
}