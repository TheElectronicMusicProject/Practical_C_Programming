#include <stdio.h>
#include <string.h>

char *find_zero(char *string);

char big_string[1000];
char *big_string_ptr;

int main(void){
	printf("Inserire stringa: ");
	fgets(big_string, sizeof(big_string), stdin);
	*(big_string + strlen(big_string) - 1) = '\0';
	printf("Stringa immessa: %s\n", big_string);
	big_string_ptr = find_zero(big_string);
	int i = 0;
	printf("## %c\n", *big_string_ptr);
	for(i = 0; *big_string_ptr != '\0'; ++i){
		printf("%d\t %c\n", i, *big_string_ptr);
		big_string_ptr++;
	}
	return(0);
}

char *find_zero(char *string){
	char *ptr;
	while(*string != '\0'){
		ptr = string;
		if(*string != ' ')
			break;
		++string;
	}
	printf("## %c\n", *ptr);
	return (ptr);
}