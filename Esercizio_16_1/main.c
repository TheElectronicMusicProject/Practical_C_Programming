#include <stdio.h>

float read_float(char *input);
void write_float(float input, char *output);
void add_float(char *in1, char *in2, char *out);
void mul_float(char *in1, char *in2, char *out);
void sub_float(char *in1, char *in2, char *out);
void div_float(char *in1, char *in2, char *out);

int main(void){
	char n1[20] = "1.234E+5";
	char n2[20];
	char out[20];
	float input = read_float(n1);
	printf("%.3E\n", input);
	write_float(input, n2);
	printf("%s\n", n2);
	add_float(n1, n2, out);
	float res_sum = read_float(out);
	printf("Somma: %.3E + %.3E = %.3E\n", read_float(n1), read_float(n2), res_sum);
	mul_float(n1, n2, out);
	float res_mul = read_float(out);
	printf("Somma: %.3E * %.3E = %.3E\n", read_float(n1), read_float(n2), res_mul);
	sub_float(n1, n2, out);
	float res_sub = read_float(out);
	printf("Somma: %.3E - %.3E = %.3E\n", read_float(n1), read_float(n2), res_sub);
	div_float(n1, n2, out);
	float res_div = read_float(out);
	printf("Somma: %.3E / %.3E = %.3E\n", read_float(n1), read_float(n2), res_div);
	return (0);
}

void add_float(char *in1, char *in2, char *out){
	float f1 = read_float(in1);
	float f2 = read_float(in2);
	float foutput = f1 + f2;
	write_float(foutput, out);
	return;
}

void mul_float(char *in1, char *in2, char *out){
	float f1 = read_float(in1);
	float f2 = read_float(in2);
	float foutput = f1 * f2;
	write_float(foutput, out);
	return;
}

void sub_float(char *in1, char *in2, char *out){
	float f1 = read_float(in1);
	float f2 = read_float(in2);
	float foutput = f1 - f2;
	write_float(foutput, out);
	return;
}

void div_float(char *in1, char *in2, char *out){
	float f1 = read_float(in1);
	float f2 = read_float(in2);
	float foutput = f1 / f2;
	write_float(foutput, out);
	return;
}

// Legge un float da stringa
float read_float(char *input){
	float number = 0;
	sscanf(input, "%f", &number);
	return number;
}

// Mette un float nella stringa
void write_float(float input, char *output){
	sprintf(output, "%.3E", input);
	return;
}