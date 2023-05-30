#include <stdio.h>
#include <string.h>

unsigned int counts(char number, char array[], int length);
void test(void);

char line[100];
char line_number[100];
char number;

int main(void){
	/*while(1){
		printf("Insert a string: ");
		fgets(line, sizeof(line), stdin);
		printf("Insert a number: ");
		fgets(line_number, sizeof(line_number), stdin);
		sscanf(line_number, "%c", &number);
		int i = 0;
		while(line[i] != '\n')
			++i;
		printf("%u times.\n", counts(number, line, i));
	}*/
	test();
	return (0);
}

/*unsigned int counts(char number, char array[], int length){
	unsigned int counter = 0;
	int i = 0;
	for(i = 0; i < length; ++i){
		if(array[i] == number){
			++counter;
		}
	}
	return counter;
}*/

unsigned int counts(char number, char array[], int length){
	unsigned int counter = 0;
	if(length > 0){
		if(array[length - 1] == number){
			++counter;
		}
		counter += counts(number, array, length - 1);
	}
	return counter;
}

void test(void){
	char lines1[20] = "949221999";
	(counts('9', lines1, 9) == 5) ? printf("OK\n") : printf("NO\n");
	char lines2[20] = "123123123";
	(counts('1', lines2, 9) == 3) ? printf("OK\n") : printf("NO\n");
	char lines3[20] = "123123123";
	(counts('3', lines3, 9) == 3) ? printf("OK\n") : printf("NO\n");
	char lines4[20] = "abc123A";
	(counts('3', lines4, 7) == 1) ? printf("OK\n") : printf("NO\n");
}