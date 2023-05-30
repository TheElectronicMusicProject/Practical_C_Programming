#include <stdio.h>

struct mail_label{
	char name[20];
	char surname[20];
	char address[20];
	unsigned int number;
	char city[20];
	char province[3];
	char state[20];
} user1;

char ch;

int main(void){
	FILE *input = fopen("store.txt", "r");
	FILE *output = fopen("out.txt", "a");
	while(fgetc(input) != '\n');
	fscanf(input, "%s", user1.name);
	printf("Name: %s\n", user1.name);
	while(fgetc(input) != '\n');
	fscanf(input, "%s", user1.surname);
	printf("Surname: %s\n", user1.surname);
	while(fgetc(input) != '\n');
	fscanf(input, "%s", user1.address);
	printf("Address: %s\n", user1.address);
	while(fgetc(input) != '\n');
	fscanf(input, "%u", &user1.number);
	printf("Number: %u\n", user1.number);
	while(fgetc(input) != '\n');
	fscanf(input, "%s", user1.city);
	printf("City: %s\n", user1.city);
	while(fgetc(input) != '\n');
	fscanf(input, "%s", user1.province);
	printf("Province: %s\n", user1.province);
	while(fgetc(input) != '\n');
	fscanf(input, "%s", user1.state);
	printf("State: %s\n", user1.state);
	fclose(input);
	fclose(output);
	return (0);
}