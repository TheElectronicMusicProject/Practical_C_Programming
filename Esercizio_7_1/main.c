#include <stdio.h>

/*****************************************************************
 * main.c -- unit conversion from English to metric				 *
 *																 *
 * Usage: insert a value followed by the source unit			 *
 *		  e.g. "1 m" as returns 1.6093 km						 *
 *																 *
 *****************************************************************/
 
float input;		/* source number */
float output;		/* output number */
char unit;			/* unit of measure */
char line[100];		/* input buffer */
 
int main(void){
	while(1){
		/* Reads input */
		printf("Please insert a number followed by its unit: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%f %c", &input, &unit);
		if(unit == 'm'){
			output = input * 1.6093;
			printf("%f miles to %f kilometers.\n", input, output);
		}
		else if(unit == 'i'){
			output = input * 2.54;
			printf("%f inches to %f centimeters.\n", input, output);
		}
		else if(unit == 'f'){
			output = input * 30.48;
			printf("%f foots to %f centimeters.\n", input, output);
		}
		else if(unit == 'p'){
			output = input * 453.59237;
			printf("%f pounds(libbra) to %f centimeters.\n", input, output);
		}
		else if(unit == 'q'){
			output = input * 568;
			printf("%f quarts to %f ml.\n", input, output);
		}
		else{
			printf("Not a valid expression. Exit.");
			break;
		}
	}
	return (0);
}