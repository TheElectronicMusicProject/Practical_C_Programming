#include <stdio.h>

int width = 3;
int height = 5;
int area;
int perimeter;

int main(void){
	perimeter = width + height;
	area = width * height;
	printf("Perimetro: %d, area: %d", perimeter, area);
	return 0;
}