#include <stdio.h>

unsigned int minutes;
unsigned int t_hours = 0;
unsigned int t_minutes = 0;
char strings[20];

int main(void){
	printf("Minuti: ");
	fgets(strings, sizeof(strings), stdin);
	sscanf(strings, "%u", &minutes);
	t_hours = minutes / 60;
	t_minutes = minutes - t_hours * 60;
	printf("%u ore e %u minuti", t_hours, t_minutes);
	return (0);
}