#include <stdio.h>

#ifndef MACRO
#define MACRO
#define BOOL(x) {						\
					if((x) % 10 == 0){	\
						y = 1;		\
					}					\
					else{				\
						y = 0;		\
					}					\
				}
#endif /* MACRO */

char line[100];
unsigned int input = 0;
char y = 0;

int main(void){
	printf("Insert a number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%u", &input);
	BOOL(input);
	(y == 1) ? printf("TRUE\n") : printf("FALSE\n");
	return (0);
}