#include <stdio.h>
#include <string.h>

struct airplane{
	char number[8];
	char start_code[4];
	char end_code[4];
	char start_hour[6];
	char end_hour[6];
};

struct airplane roma_parigi = {
	"FR 9631",
	"ROM",
	"PAR",
	"06:45",
	"08:55"
};

void print_struct(struct airplane input);

int main(void){
	struct airplane roma_newyork;
	strcpy(roma_newyork.number, "NY 4893");
	strcpy(roma_newyork.start_code, "ROM");
	strcpy(roma_newyork.end_code, "PAR");
	strcpy(roma_newyork.start_hour, "04:45");
	strcpy(roma_newyork.end_hour, "21:45");
	print_struct(roma_newyork);
	print_struct(roma_parigi);
	return (0);
}

void print_struct(struct airplane input){
	printf("#: %s\n", input.number);
	printf("Originating code: %s\n", input.start_code);
	printf("Destination code: %s\n", input.end_code);
	printf("Starting time: %s\n", input.start_hour);
	printf("Arrival time: %s\n", input.end_hour);
	return;
}