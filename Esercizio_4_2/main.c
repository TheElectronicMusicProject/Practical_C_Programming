#include <stdio.h>

int i = 0;
int j = 0;

int main(void){
	for(i = 0; i < 7; ++i){
		for(j = 0; j < 5; ++j){
			printf("*");
			if(i == 1 || i == 2 || i == 4 || i == 5){
				break;
			}
		}
		printf("\n");
	}
	return 0;
}