#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void row_dot_col(int* in_m1, unsigned int nrow1, unsigned int ncol1,
				int* in_m2, unsigned int nrow2, unsigned int ncol2,
				int* out_m3);

FILE *f_matrix1;
FILE *f_matrix2;
FILE *f_matrix3;
char line[100];
int i = 0;
int j = 0;
char temp;
int temp_val;
unsigned int col1 = 0, row1 = 0;
unsigned int col2 = 0, row2 = 0;

// Prodotto riga per colonna: il numero di colonne della prima matrice deve essere uguale al
// numero di righe della seconda.
int main(void){
	/* LETTURA DELLA PRIMA MATRICE */
	printf("Inserire nome file prima matrice: ");
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';
	f_matrix1 = fopen(line, "r");
	if(f_matrix1 == NULL){
		fprintf(stderr, "File %s not found", line);
		exit(8);
	}
	do{
		fscanf(f_matrix1, "%d", &temp_val);
		temp = fgetc(f_matrix1);
		if(temp == '\t')
			++i;
		//printf("i = %d and temp = %c while temp_val = %d\n", i, temp, temp_val);
	}while(temp != EOF && temp != '\n');
	col1 = i + 1;
	if(temp != EOF)
		++row1;
	do{
		fscanf(f_matrix1, "%d", &temp_val);
		temp = fgetc(f_matrix1);
		if(temp == '\n')
			++row1;
	}while(temp != EOF);
	++row1;				/* L'ultima riga non ha \n, quindi devo aggiungerne una */
	rewind(f_matrix1);	/* Ricomincio dall'inizio del file */
	printf("cols %d, rows %d\n", col1, row1);
	int matrix1[row1][col1];
	for(i = 0; i < row1; ++i){
		for(j = 0; j < col1; ++j){
			fscanf(f_matrix1, "%d", &matrix1[i][j]);
			//printf("%d, %d,\t%d\n", i, j, matrix1[i][j]);
		}
	}
	fclose(f_matrix1);
	/* LETTURA DELLA SECONDA MATRICE */
	printf("Inserire nome file seconda matrice: ");
	fgets(line, sizeof(line), stdin);
	line[strlen(line) - 1] = '\0';
	f_matrix2 = fopen(line, "r");
	if(f_matrix2 == NULL){
		fprintf(stderr, "File %s not found", line);
		exit(8);
	}
	i = 0;				/* Va reimpostato a zero! */
	do{
		fscanf(f_matrix2, "%d", &temp_val);
		temp = fgetc(f_matrix2);
		//printf("temp = %c\n", temp);
		if(temp == '\t')
			++i;
	}while(temp != EOF && temp != '\n');
	col2 = i + 1;
	if(temp != EOF)
		++row2;
	do{
		fscanf(f_matrix2, "%d", &temp_val);
		temp = fgetc(f_matrix2);
		if(temp == '\n')
			++row2;
	}while(temp != EOF);
	++row2;				/* L'ultima riga non ha \n, quindi devo aggiungerne una */
	rewind(f_matrix2);	/* Ricomincio dall'inizio del file */
	printf("cols %d, rows %d\n", col2, row2);
	int matrix2[row2][col2];
	for(i = 0; i < row2; ++i){
		for(j = 0; j < col2; ++j){
			fscanf(f_matrix2, "%d", &matrix2[i][j]);
			//printf("%d, %d,\t%d\n", i, j, matrix2[i][j]);
		}
	}
	fclose(f_matrix2);
	/* INIZIO DEL PROGRAMMA */
	if(col1 != row2){
		fflush(stdout);
		fprintf(stderr, "ERROR: there are %u cols in first matrix and %u rows in the second one", col1, row2);
		exit(8);
	}
	int matrix3[row1][col2];	/* La nuova matrice ha lo stesso numero di righe della prima e stesso numero di colonne della seconda */
	clock_t begin = clock();	/* Prendo primo tempo */
	row_dot_col(&matrix1[0][0], row1, col1, &matrix2[0][0], row2, col2, &matrix3[0][0]);
	clock_t end = clock();		/* Prendo tempo di fine */
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;		/* Tempo risultante */
	f_matrix3 = fopen("m3.txt", "a");
	//printf("cols %d, rows %d\n", row1, col2);
	for(i = 0; i < row1; ++i){
		for(j = 0; j < col2; ++j){
			fprintf(f_matrix3, "%d\t", matrix3[i][j]);
		}
		fprintf(f_matrix3, "\n");
	}
	fclose(f_matrix3);
	printf("Time spent is: %f milliseconds\n", time_spent);
	printf("END!");
	return (0);
}

void row_dot_col(int* in_m1, unsigned int nrow1, unsigned int ncol1,
				int* in_m2, unsigned int nrow2, unsigned int ncol2,
				int* out_m3){
	unsigned int r = 0, c = 0, j = 0, i = 0;
	int temp_val = 0;
	for(r = 0; r < nrow1; ++r){
		for(c = 0; c < ncol2; ++c){
			for(j = 0; j < ncol1; ++j){
				temp_val += *(in_m1 + j) * *(in_m2 + c + j * ncol2);
				//printf("%d, %d\n", r, c);
				//printf("%d * %d = %d\n", *(in_m1 + r + j), *(in_m2 + c + j * ncol2), temp_val);
			}
			*(out_m3 + i + c) = temp_val;
			//printf("row = %d, col = %d, index = %d\t value = %d\n", r, c, c + i, temp_val);
			temp_val = 0;
		}
		in_m1 += ncol1 - 1;
		i += nrow1 - 1;
	}
	return;
}