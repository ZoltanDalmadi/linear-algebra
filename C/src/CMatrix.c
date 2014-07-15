#include "CMatrix.h"

MATRIX* createMatrix(size_t rows, size_t cols)
{
    MATRIX *m = (MATRIX*)calloc(1, sizeof(MATRIX));
    m->_rows = rows;
    m->_cols = cols;
    m->_data = (int **)calloc(rows, sizeof(int *));

    for (size_t i = 0; i < rows; ++i)
        m->_data[i] = (int *)calloc(cols, sizeof(int));

    return m;
}

MATRIX* copyMatrix(MATRIX *m)
{
    MATRIX *copy = createMatrix(m->_rows, m->_cols);

    for (size_t i = 0; i < copy->_rows; ++i)
    {
        for (size_t j = 0; j < copy->_cols; ++j)
            copy->_data[i][j] = m->_data[i][j];
    }

    return copy;
}

void initMatrix(MATRIX* m, int* a)
{
    for (size_t i = 0; i < m->_rows; ++i)
    {
        for (size_t j = 0; j < m->_cols; ++j)
            m->_data[i][j] = a[i * m->_cols + j];
    }
}

MATRIX* createIdentityMatrix(size_t rowcols)
{
    MATRIX *m = createMatrix(rowcols, rowcols);

    for (size_t i = 0; i < rowcols; ++i)
        m->_data[i][i]++;

    return m;
}

void destroyMatrix(MATRIX* m)
{
    for (size_t i = 0; i < m->_rows; ++i)
        free(m->_data[i]);

    free(m->_data);
    free(m);
    m = NULL;
}

void printMatrix(MATRIX* m)
{
    for (size_t i = 0; i < m->_rows; ++i)
    {
        printf("|");

        for (size_t j = 0; j < m->_cols; ++j)
        {
            printf("%d", m->_data[i][j]);

            if (j == m->_cols - 1)
                printf("|\n");
            else
                printf(" ");
        }
    }

    printf("\n");
}

MATRIX* transpose(MATRIX* m)
{
    MATRIX *trans = createMatrix(m->_cols, m->_rows);

    for (size_t i = 0; i < m->_cols; ++i)
    {
        for (size_t j = 0; j < m->_rows; ++j)
            trans->_data[i][j] = m->_data[j][i];
    }

    return trans;
}

MATRIX* concatMatrices(MATRIX* A, MATRIX* B)
{
    // check equal rows
    if (A->_rows != B->_rows)
    {
        fprintf(stderr, "Matrices cannot be concatenated!\n");
        exit(EXIT_FAILURE);
    }

    // create concatenated matrix
    MATRIX *concat = createMatrix(A->_rows, A->_cols + B->_cols);

    // insert columns next to each other
    for (size_t i = 0; i < concat->_cols; ++i)
    {
        for (size_t j = 0; j < concat->_rows; ++j)
        {
            if (i < A->_cols)
                concat->_data[j][i] = A->_data[j][i];
            else
                concat->_data[j][i] = B->_data[j][i - A->_cols];
        }
    }

    return concat;
}

void swapRows(MATRIX *m, size_t a, size_t b)
{
    // just swap the pointers
    int *temp = m->_data[a];
    m->_data[a] = m->_data[b];
    m->_data[b] = temp;
}

MATRIX* addMatrices(MATRIX* A, MATRIX* B)
{
    if (A->_rows != B->_rows && A->_cols != B->_cols)
    {
        fprintf(stderr, "Matrices cannot be added!\n");
        exit(EXIT_FAILURE);
    }

    MATRIX *result = createMatrix(A->_rows, A->_cols);

    for (size_t i = 0; i < result->_rows; ++i)
    {
        for (size_t j = 0; j < result->_cols; ++j)
            result->_data[i][j] = A->_data[i][j] + B->_data[i][j];
    }

    return result;
}

void scalarMultiplyMatrix(MATRIX* m, int scalar)
{
    for (size_t i = 0; i < m->_rows; ++i)
    {
        for (size_t j = 0; j < m->_cols; ++j)
            m->_data[i][j] *= scalar;
    }
}
