#include <stdio.h>

const int hor = 5;	/* # of horizontal - */
const int vert = 3;	/* # of vertical | */
const int dim = 8;	/* dimension of the grid */

int main(void){
	int i = 0, j = 0;
	for(i = 0; i < vert * dim + dim + 1; ++i){
		for(j = 0; j < hor * dim + dim + 1; ++j){
			if(i % (vert + 1) == 0){
				if(j % (hor + 1) == 0){
					printf("+");
				}
				else{
					printf("-");
				}
			}
			else{
				if(j % (hor + 1) == 0){
					printf("|");
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}