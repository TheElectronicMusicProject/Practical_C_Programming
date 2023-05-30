#include <stdio.h>

unsigned int w_hours = 0;
unsigned int h_wage = 0;
float w_pay = 0;
char line[100];

int main(void){
	int extra_hours;
	printf("Enter weekly hours and hourly wage: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%u %u", &w_hours, &h_wage);
	if(w_hours < 40)
		extra_hours = 40 % w_hours;
	else
		extra_hours = w_hours % 40;
	w_pay = (w_hours - extra_hours) * h_wage + extra_hours * h_wage * 1.5;
	printf("H extra: %d\n", extra_hours);
	printf("Weekly pay: %f", w_pay);
	return (0);
}