#include <stdio.h>
#include <string.h>

#define ELEMENTS 7

struct airplane{
	char number[8];
	char start_code[4];
	char end_code[4];
	char start_hour[6];
	char end_hour[6];
};

void print_struct(struct airplane input);

struct airplane from_to[ELEMENTS] = {
	{"FR 9631",
	"ROM",
	"PAR",
	"06:45",
	"08:55"},
	
	{"NY 4893",
	"ROM",
	"NEY",
	"04:45",
	"21:45"},
	
	{"NY 4651",
	"ROM",
	"NEY",
	"17:32",
	"21:45"},
	
	{"NY 4793",
	"ROM",
	"NEY",
	"18:00",
	"02:55"},
	
	{"RM 7890",
	"NEY",
	"ROM",
	"18:00",
	"02:55"},
	
	{"DB 1567",
	"PAR",
	"DUB",
	"01:45",
	"21:17"},
	
	{"CT 1235",
	"ROM",
	"CAT",
	"07:32",
	"08:45"},
};

char line[100];
char startinpoint[4];
char endingpoint[4];

int main(void){
	printf("Insert originating and destination code: ");
	fgets(line, sizeof(line), stdin);
	int i = 0;
	while(line[i] != ' '){
		startinpoint[i] = line[i];
		++i;
	}
	startinpoint[i] = '\0';
	++i;
	while(line[i] != '\n'){
		endingpoint[i - 4] = line[i];
		++i;
	}
	endingpoint[i - 4] = '\0';
	for(i = 0; i < ELEMENTS; ++i){
		if(!strcmp(from_to[i].start_code, startinpoint) && !strcmp(from_to[i].end_code, endingpoint)){
			print_struct(from_to[i]);
			printf("\n");
		}
	}
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