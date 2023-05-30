#include <stdio.h>
#include <string.h>

#define X_SIZE  60
#define Y_SIZE  30

int matrix[X_SIZE][Y_SIZE];

#define INIT_MATRIX()   (memset(matrix, 1, sizeof(matrix)))

int
main (int argc, char * argv[])
{
    register int * p_matrix = NULL;

    INIT_MATRIX();

    for (p_matrix = &matrix[0][0]; p_matrix <= &matrix[X_SIZE - 1][Y_SIZE - 1]; ++p_matrix)
    {
        printf("%d\n", *p_matrix);
    }

    return (0);
}