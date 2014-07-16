#ifndef CMATRIX_H
#define CMATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    size_t _rows;
    size_t _cols;
    double **_data;
} MATRIX;

MATRIX* createMatrix(size_t, size_t);

MATRIX* copyMatrix(MATRIX*);

void initMatrix(MATRIX*, double*);

MATRIX* createIdentityMatrix(size_t);

void destroyMatrix(MATRIX*);

void printMatrix(MATRIX*);

MATRIX* transpose(MATRIX*);

MATRIX* concatMatrices(MATRIX*, MATRIX*);

void swapRows(MATRIX*, size_t, size_t);

MATRIX* addMatrices(MATRIX*, MATRIX*);

void scalarMultiplyMatrix(MATRIX*, double);

MATRIX* multiplyMatrices(MATRIX*, MATRIX*);

MATRIX* inverse(MATRIX*);

#endif /* end of include guard: CMATRIX_H */
