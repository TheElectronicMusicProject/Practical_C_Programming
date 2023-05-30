#include <stdio.h>

#define IS_DIGIT(x)	{	\
					if((x) == '0' || (x) == '1' || (x) == '2' || (x) == '3' || (x) == '4' || (x) == '5' || (x) == '6' || (x) == '7' || (x) == '8' || (x) == '9'){	\
						y = 1;	\
					}		\
					else{	\
						y = 0;	\
					}		\
					}

char line[100];
int y = 0;
char flag = 0;

int main(void){
	printf("Insert a string: ");
	fgets(line, sizeof(line), stdin);
	int i = 0;
	for(i = 0; line[i] != '\n'; ++i){
		IS_DIGIT(line[i])
		if(y == 0){
			flag = 1;
			printf("%c is not decimal\n", line[i]);
		}
		else{
			printf("%c is decimal\n", line[i]);
		}
	}
	(flag == 0) ? printf("All decimal values") : printf("There are problems");
	return (0);
}