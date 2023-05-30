#include <stdio.h>
#include <math.h>

float p1_x = 0;
float p1_y = 0;
float p2_x = 0;
float p2_y = 0;
float distance = 0;
char string[100];

int main(void){
	printf("Insert x,y coordinates for P1: ");
	fgets(string, sizeof(string), stdin);
	sscanf(string, "%f %f", &p1_x, &p1_y);
	printf("Insert x,y coordinates for P2: ");
	fgets(string, sizeof(string), stdin);
	sscanf(string, "%f %f", &p2_x, &p2_y);
	distance = sqrt((p1_x - p2_x) * (p1_x - p2_x) + (p1_y - p2_y) * (p1_y - p2_y));
	printf("Distance is: %f", distance);
	return (0);
}