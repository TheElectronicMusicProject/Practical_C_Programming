#include <stdio.h>
#include <string.h>

int begins(char string1[], char string2[]); /* true if string1 begins with string2 */
// int begins(char *string1, char *string2);

char line1[100];
char line2[100];

int main(void){
	while(1){
		printf("Insert two strings, I'll understand if the second string is at the beginning of the first one:\n");
		fgets(line1, sizeof(line1), stdin);
		fgets(line2, sizeof(line2), stdin);
		(begins(line1, line2) == 0) ? printf("NO\n\n") : printf("YES\n\n");
	}
	return (0);
}

int begins(char string1[], char string2[]){
	int check = 0;
	int i = 0;
	if(strlen(string1) - i >= strlen(string2)){
		for(i = 0; string2[i] != '\n'; ++i){
			if(string2[i] != string1[i]){
				check = 0;
				break;
			}
			check = 1;
		}
	}
	return check;
}