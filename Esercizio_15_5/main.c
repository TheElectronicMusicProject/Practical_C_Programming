#include <stdio.h>
#include <time.h>
#include <string.h>

#define LENGTH 50

// void *memcpy(void *dest, const void *src, size_t n);
void *copiamem(void *dest, const void *src, size_t n);

int main(void){
	clock_t start, end;
	char sorgente[LENGTH] = "FILIPPO";
	char destinazione[LENGTH];
	start = clock();
	//memcpy(destinazione, sorgente, strlen(sorgente) + 1);
	copiamem(destinazione, sorgente, strlen(sorgente) + 1);
	end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("After memcpy dest = %s\n", destinazione);
	printf("Time = %f", time);
	return (0);
}

void *copiamem(void *dest, const void *src, size_t n){
	int i = 0;
	void *dest_ptr = &dest;
	char *dest_ch = dest;
	const char *src_ch = src;
	for(i = 0; i < n; ++i){
		*(dest_ch + i) = *(src_ch + i);
	}
	return (dest_ptr);
}