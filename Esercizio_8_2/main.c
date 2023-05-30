#include <stdio.h>

double i_tot_res = 0;	/* Inverse total resistance */
double tot_res = 0;		/* Total parallel resistance */
float res = 0;			/* Read value */
char line[20];			/* Input buffer */

int main(void){
	while(1){
		i_tot_res = 0;
		while(1){
			printf("Insert some resistance values: ");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%f", &res);
			if(res > 0)
				i_tot_res += 1.0 / res;
			else
				break;
		}
		tot_res = 1.0 / i_tot_res;
		printf("Parallel resistance:\t%f\n", tot_res);
	}
	return(0);
}