#include <stdio.h>

unsigned int length = 0;
int line[] = {-1, 0, 1, 2, 3, 5, 9, -95, -1859, 666, 3, 2, 978, -1000, 455, 8, 1000};
int max = 0;

int find_max(int string[], unsigned int len);

int main(void){
	length = 16;
	max = find_max(line, length);
	printf("%d is the maximum value", max);
	return 0;
}

int find_max(int string[], unsigned int len){
	int i = 0;
	int maximum = 0;
	for(i = 0; i <= len; ++i){
		if(string[i] > maximum){
			maximum = string[i];
		}
	}
	return maximum;
}