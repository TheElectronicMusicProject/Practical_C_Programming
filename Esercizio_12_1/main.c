#include <stdio.h>
#include <string.h>

#define SIZE 100

struct mail_struct{
	char name_surname[SIZE];		/* Name and surname */
	char city[SIZE];				/* City where you live */
	char road[SIZE];				/* Name of road */
	unsigned char number;		/* Number of the road */
	unsigned int zip_code;		/* Zip code */
	char email[SIZE];			/* Email */
};

void print_struct(struct mail_struct input, unsigned int size);

struct mail_struct user1 = {
	"Filippo Graziani",
	"Faenza",
	"Via Accarisi",
	133,
	48018,
	"filorun@libero.it"
};

int main(void){
	// Per modificare i contenuti runtime
	//strcpy(user1.name_surname, "PIPPONE FILIPPONE");
	print_struct(user1, SIZE);
	return (0);
}

void print_struct(struct mail_struct input, unsigned int size){
	int i = 0;
	// Maniera equivalente
	// printf("Name & surname: %s\n", input.name_surname);
	printf("Name & surname: ");
	for(i = 0; i < size && input.name_surname[i] != '\0'; ++i){
		printf("%c", input.name_surname[i]);
	}
	printf("\nCity: ");
	for(i = 0; i < size && input.city[i] != '\0'; ++i){
		printf("%c", input.city[i]);
	}
	printf("\nRoad: ");
	for(i = 0; i < size && input.road[i] != '\0'; ++i){
		printf("%c", input.road[i]);
	}
	printf(",\t%d\n", input.number);
	printf("Zip code: %u\n", input.zip_code);
	printf("Email: ");
	for(i = 0; i < size && input.email[i] != '\0'; ++i){
		printf("%c", input.email[i]);
	}
	return;
}