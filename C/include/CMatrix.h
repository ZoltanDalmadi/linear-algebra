#ifndef CMATRIX_H
#define CMATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    unsigned _rows;
    unsigned _cols;
    int **_data;
} MATRIX;

MATRIX* createMatrix(unsigned, unsigned);

MATRIX* createIdentityMatrix(unsigned);

void destroyMatrix(MATRIX*);

void printMatrix(MATRIX*);

MATRIX* transpose(MATRIX*);

#endif /* end of include guard: CMATRIX_H */
