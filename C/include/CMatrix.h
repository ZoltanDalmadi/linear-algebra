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

void initMatrix(MATRIX*, int*);

MATRIX* createIdentityMatrix(unsigned);

void destroyMatrix(MATRIX*);

void printMatrix(MATRIX*);

MATRIX* transpose(MATRIX*);

MATRIX* concatMatrices(MATRIX*, MATRIX*);

#endif /* end of include guard: CMATRIX_H */
