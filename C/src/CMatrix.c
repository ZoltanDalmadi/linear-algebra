#include "CMatrix.h"

MATRIX* createMatrix(unsigned rows, unsigned cols)
{
    MATRIX *m = (MATRIX*)calloc(1, sizeof(MATRIX));
    m->_rows = rows;
    m->_cols = cols;
    m->_data = (int **)calloc(rows, sizeof(int *));

    for (int i = 0; i < rows; ++i)
        m->_data[i] = (int *)calloc(cols, sizeof(int));

    return m;
}

void initMatrix(MATRIX* m, int* a)
{
    for (int i = 0; i < m->_rows; ++i)
    {
        for (int j = 0; j < m->_cols; ++j)
            m->_data[i][j] = a[i * m->_cols + j];
    }
}

MATRIX* createIdentityMatrix(unsigned rowcols)
{
    MATRIX *m = createMatrix(rowcols, rowcols);

    for (int i = 0; i < rowcols; ++i)
        m->_data[i][i]++;

    return m;
}

void destroyMatrix(MATRIX* m)
{
    for (int i = 0; i < m->_rows; ++i)
        free(m->_data[i]);

    free(m->_data);
    free(m);
    m = NULL;
}

void printMatrix(MATRIX* m)
{
    for (int i = 0; i < m->_rows; ++i)
    {
        printf("|");

        for (int j = 0; j < m->_cols; ++j)
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

    for (int i = 0; i < m->_cols; ++i)
    {
        for (int j = 0; j < m->_rows; ++j)
            trans->_data[i][j] = m->_data[j][i];
    }

    return trans;
}
