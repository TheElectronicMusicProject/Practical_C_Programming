#include <stdio.h>

char line[100];
char letter;

int main(void){
	while(1){
		printf("Type a letter: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c", &letter);
		switch(letter){
			case 'A':
			/* Fall through */
			case 'a':
			/* Fall through */
			case 'E':
			/* Fall through */
			case 'e':
			/* Fall through */
			case 'I':
			/* Fall through */
			case 'i':
			/* Fall through */
			case 'O':
			/* Fall through */
			case 'o':
			/* Fall through */
			case 'U':
			/* Fall through */
			case 'u':
				printf("Vowel\n");
				break;
			case 'B':
			/* Fall through */
			case 'b':
			/* Fall through */
			case 'C':
			/* Fall through */
			case 'c':
			/* Fall through */
			case 'D':
			/* Fall through */
			case 'd':
			/* Fall through */
			case 'F':
			/* Fall through */
			case 'f':
			/* Fall through */
			case 'G':
			/* Fall through */
			case 'g':
			/* Fall through */
			case 'H':
			/* Fall through */
			case 'h':
			/* Fall through */
			case 'J':
			/* Fall through */
			case 'j':
			/* Fall through */
			case 'K':
			/* Fall through */
			case 'k':
			/* Fall through */
			case 'L':
			/* Fall through */
			case 'l':
			/* Fall through */
			case 'M':
			/* Fall through */
			case 'm':
			/* Fall through */
			case 'N':
			/* Fall through */
			case 'n':
			/* Fall through */
			case 'P':
			/* Fall through */
			case 'p':
			/* Fall through */
			case 'Q':
			/* Fall through */
			case 'q':
			/* Fall through */
			case 'R':
			/* Fall through */
			case 'r':
			/* Fall through */
			case 'S':
			/* Fall through */
			case 's':
			/* Fall through */
			case 'T':
			/* Fall through */
			case 't':
			/* Fall through */
			case 'V':
			/* Fall through */
			case 'v':
			/* Fall through */
			case 'W':
			/* Fall through */
			case 'w':
			/* Fall through */
			case 'X':
			/* Fall through */
			case 'x':
			/* Fall through */
			case 'Y':
			/* Fall through */
			case 'y':
			/* Fall through */
			case 'Z':
			/* Fall through */
			case 'z':
				printf("Consonant\n");
				break;
			default:
				printf("Not a letter\n");
				break;
		}
	}
	return (0);
}