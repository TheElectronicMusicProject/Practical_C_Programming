#include <stdio.h>

#define X_SIZE 25	/* X_SIZE punti lungo x */
#define Y_SIZE 25	/* Y_SIZE punti lungo y */

void print_graphics(void);	/* Prototipo */

/* La funzione SET_BIT imposta un bit nella maniera seguente:
 * - lungo x si ha una divisione per 8 bit alla volta, così da poter selezionare un settore;
 * - lungo y invece no;
 * - si parte dal bit più significativo (del settore x/8) e lo si trasla di una quantità che dipende da x % 8,
 * in altre parole se x > 7 ritorna a 0 ma facente parte del settore successivo. */
#define SET_BIT(x, y) graphics[(x) / 8][y] |= (0x80 >> ((x) % 8))

/* Questa macro resetta un bit */
#define CLEAR_BIT(x, y) graphics[(x) / 8][y] &= ~(0x80 >> ((x) % 8))

/* Questa macro verifica il valore di un bit */
#define TEST_BIT(x, y) {	\
						if(graphics[(x) / 8][y] & (0x80 >> ((x) % 8)))	\
							test = 1;	\
						else	\
							test = 0;	\
						}

/* Impacchetto i caratteri lungo X in modo che ogni 8 punti siano in un byte */
/* I caratteri lungo Y vengono lasciati tali */
unsigned char graphics[X_SIZE / 8][Y_SIZE];	/* Array di caratteri */

int main(void){
	int locx;
	int locy;
	//int test;
	/* Stampa linea: per farlo arriva fino a X_SIZE percorrendo quindi tutti i settori */
	for(locx = 0; locx < X_SIZE; ++locx){
		for(locy = 0; locy < Y_SIZE; ++locy){
			if(locx == 0 || locx == X_SIZE - 1)
				SET_BIT(locx, locy);
			if(locy == 0 || locy == Y_SIZE - 1)
				SET_BIT(locx, locy);
			//TEST_BIT(loc, loc);
			//printf("## in x = %d, y = %d => %d\n", loc, loc, test);
		}
	}
	print_graphics();
	return(0);
}

void print_graphics(void){
	int x, y;			/* Coordinate del punto */
	unsigned int bit;	/* Bit da testare */
	/* Scansione per righe */
	for(y = 0; y < Y_SIZE; ++y){
		/* Scansione per settori */
		for(x = 0; x < X_SIZE / 8; ++x){
			/* Test del bit da impostare, partendo dal più significativo */
			for(bit = 0x80; bit > 0; bit = (bit >> 1)){
				/* Caso di bit da impostare */
				if((graphics[x][y] & bit) != 0)
					printf("X ");
				else
					printf(". ");
			}
		}
		for(bit = 0x80; bit > (0x80 >> (X_SIZE % 8)); bit = (bit >> 1)){
			/* Caso di bit da impostare */
			if((graphics[x][y] & bit) != 0)
				printf("X ");
			else
				printf(". ");
		}
		printf("\n");
	}
	return;
}