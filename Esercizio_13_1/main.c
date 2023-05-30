#include <stdio.h>

#define SIZE 100

void put_zero(int *array_numbers, int size);

int array[SIZE];

int main(void){
	int i = 0;
	// Inizializzo
	for(i = 0; i < SIZE; ++i){
		*(array + i) = i;
		(i < SIZE - 1) ? printf("%d, ", *(array + i)) : printf("%d.\n", *(array + i));
	}
	// Imposto a zero
	put_zero(array, SIZE);
	for(i = 0; i < SIZE; ++i)
		(i < SIZE - 1) ? printf("%d, ", *(array + i)) : printf("%d.\n", *(array + i));
	return (0);
}

void put_zero(int *array_numbers, int size){
	int *i = array_numbers;
	while(array_numbers - i < size){
		*(array_numbers) = 0;
		++array_numbers;
	}
	return;
}