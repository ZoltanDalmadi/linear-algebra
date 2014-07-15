#ifndef CMATRIX_H
#define CMATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    size_t _rows;
    size_t _cols;
    int **_data;
} MATRIX;

MATRIX* createMatrix(size_t, size_t);

void initMatrix(MATRIX*, int*);

MATRIX* createIdentityMatrix(size_t);

void destroyMatrix(MATRIX*);

void printMatrix(MATRIX*);

MATRIX* transpose(MATRIX*);

MATRIX* concatMatrices(MATRIX*, MATRIX*);

void swapRows(MATRIX *m, size_t, size_t);

#endif /* end of include guard: CMATRIX_H */
