#include <stdio.h>

unsigned int year = 0;
char line[10];
char flag = 0;

int main(void){
	while(1){
		printf("Year: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%u", &year);
		if(year < 0)
			break;
		if(year % 4 == 0){
			if(year % 100 == 0)
					if(year % 100 == 0)
						flag = 1;
					else
						flag = 0;
			else
				flag = 1;
		}else
			flag = 0;
		printf("%u is:\t", year);
		flag == 0 ? printf("Not leap year\n") : printf("Leap Year\n");
	}
	return 0;
}