#include <stdio.h>
#include <time.h>

#define SIZE 20

int main(void){
	register int i = 0;
	register long int tot = 0;
	clock_t start, end;
	int array[SIZE] = {1, 2, 8, 89, 7, -8, -99, 4 , 5, 789, 566, -56654, 8};
	start = clock();
	for(i = 0; i < SIZE; ++i){
		tot += *(array + i);
	}
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Sum of the array is: %ld calculated in %f ms", tot, time);
	return (0);
}