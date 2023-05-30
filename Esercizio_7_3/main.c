#include <stdio.h>

/* characters per second */
#define CHARACTERS 960

int size = 0;
char line[100];
float time = 0;
char unit;

int main(void){
	printf("Insert file size (e.g. 60M): ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d%c", &size, &unit);
	if(unit == 'K' || unit == 'k')
		time = 1024 * size / CHARACTERS;
	else if(unit == 'm' || unit == 'M')
		time = 1024 * 1024 * size / CHARACTERS;
	else
		time = size / CHARACTERS;
	if(time >= 60){			// da secondi a minuti
		time /= 60;
		if(time >= 60){		// da minuti a ore
			time /= 60;
			if(time >= 24){		// da ore a giorni
				time /= 24;
				printf("Time required for %d%cB: %f days", size, unit, time);
			}
			else{
				printf("Time required for %d%cB: %f hours", size, unit, time);
			}
		}
		else{
			printf("Time required for %d%cB: %f minutes", size, unit, time);
		}
	}
	else{	
	printf("Time required for %d%cB: %f seconds", size, unit, time);
	}
	return 0;
}