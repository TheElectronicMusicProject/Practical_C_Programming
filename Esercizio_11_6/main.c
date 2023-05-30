#include <stdio.h>

int number_c;
unsigned char number;
char line[100];

int main(void){
	printf("Number? ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &number_c);
	number = (char)number_c;
	int i, j = 1;
	unsigned char value, temp = 0;
	for(i = 0; (i < sizeof(char) * 8); ++i){
		value = number & (1 << (sizeof(char) * 8 - i - 1));
		if(value != 0){
			temp = temp << 1;
			temp |= 0x01;
			//printf("## Value after set: %d\t", temp);
			++j;
			//printf("## j after set: %d\n", j);
		}
	}
	//printf("## final shift: %d\n", sizeof(char) * 8 - j - 1);
	temp = temp << (sizeof(char) * 8 - j + 1);
	printf("Value: %u\n", temp);
	return (0);
}