#include "CMatrix.h"
#include <math.h>

MATRIX* createMatrix(size_t rows, size_t cols)
{
    MATRIX *m = (MATRIX*)calloc(1, sizeof(MATRIX));
    m->_rows = rows;
    m->_cols = cols;
    m->_data = (double **)calloc(rows, sizeof(double *));

    for (size_t i = 0; i < rows; ++i)
        m->_data[i] = (double *)calloc(cols, sizeof(double));

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

void initMatrix(MATRIX* m, double* a)
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
            printf("%f", m->_data[i][j]);

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
    double *temp = m->_data[a];
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

void scalarMultiplyMatrix(MATRIX* m, double scalar)
{
    for (size_t i = 0; i < m->_rows; ++i)
    {
        for (size_t j = 0; j < m->_cols; ++j)
            m->_data[i][j] *= scalar;
    }
}

MATRIX* multiplyMatrices(MATRIX* A, MATRIX* B)
{
    if (A->_cols != B->_rows)
    {
        fprintf(stderr, "Matrices cannot be multiplied!\n");
        exit(EXIT_FAILURE);
    }

    MATRIX *result = createMatrix(A->_rows, B->_cols);

    for (size_t i = 0; i < A->_rows; ++i)
    {
        for (size_t j = 0; j < B->_cols; ++j)
        {
            for (size_t k = 0; k < A->_cols; ++k)
                result->_data[i][j] += A->_data[i][k] * B->_data[k][j];
        }
    }

    return result;
}

MATRIX* inverse(MATRIX* m)
{
    if (m->_rows != m->_cols)
    {
        fprintf(stderr, "Only square matrices can be inverted!\n");
        exit(EXIT_FAILURE);
    }

    // put identity matrix next to original matrix
    MATRIX *id = createIdentityMatrix(m->_rows);
    MATRIX *aug = concatMatrices(m, id);

    // id no longer needed
    destroyMatrix(id);

    // do Gaussian Elimination
    for (size_t j = 0; j < m->_cols; ++j)
    {
        double max = 0.0;
        size_t maxRow = 0;

        // find biggest absolute value of rows 1st item
        for (size_t i = j; i < aug->_rows; ++i)
        {
            if (fabs(aug->_data[i][j]) > max)
            {
                max = fabs(aug->_data[i][j]);
                maxRow = i;
            }
        }

        // swap rows so that bigges abs value row is first
        if (maxRow != j)
            swapRows(aug, maxRow, j);

        // divide whole row with its first item
        double divisor = aug->_data[j][j];

        for (size_t i = j; i < aug->_cols; ++i)
            aug->_data[j][i] /= divisor;

        // clear entries above and below to 0
        for (size_t r = 0; r < aug->_rows; ++r)
        {
            if (r == j)
                continue;

            double mult = aug->_data[r][j];

            for (size_t i = j; i < aug->_cols; ++i)
                aug->_data[r][i] -= aug->_data[j][i] * mult;

        }
    }

    // extract inverse (right half of augmented matrix)
    MATRIX *inv = createMatrix(m->_rows, m->_cols);

    for (size_t i = 0; i < aug->_cols - m->_cols; ++i)
    {
        for (size_t j = 0; j < aug->_rows; ++j)
            inv->_data[j][i] = aug->_data[j][i + m->_cols];
    }

    // augmented matrix no longer needed
    destroyMatrix(aug);

    return inv;
}
