#include <stdio.h>

#ifndef MACRO
#define IS_HEX(x)	{	\
					if((x) == 'A' || (x) == 'B' || (x) == 'C' || (x) == 'D' || (x) == 'E' || (x) == 'F'){		\
						y = 1;	\
					}			\
					else if((x) == 'a' || (x) == 'b' || (x) == 'c' || (x) == 'd' || (x) == 'e' || (x) == 'f'){	\
						y = 1;	\
					}			\
					else{		\
						IS_DIGIT(x)	\
					}			\
					}
	
#define IS_DIGIT(x)	{	\
					if((x) == '0' || (x) == '1' || (x) == '2' || (x) == '3' || (x) == '4' || (x) == '5' || (x) == '6' || (x) == '7' || (x) == '8' || (x) == '9'){	\
						y = 1;	\
					}		\
					else{	\
						y = 0;	\
					}		\
					}
#define MACRO
#endif /* MACRO */

char line[100];
int y = 0;
char flag = 0;

int main(void){
	printf("Insert a string: ");
	fgets(line, sizeof(line), stdin);
	int i = 0;
	for(i = 0; line[i] != '\n'; ++i){
		IS_HEX(line[i])
		if(y == 0){
			flag = 1;
			printf("%c is not hex\n", line[i]);
		}
		else{
			printf("%c is hex\n", line[i]);
		}
	}
	(flag == 0) ? printf("All hex values") : printf("There are problems");
	return (0);
}