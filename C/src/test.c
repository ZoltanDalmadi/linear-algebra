#include "CMatrix.h"

int main()
{
    MATRIX *m2 = createMatrix(3, 3);

    int count = 0;

    for (int i = 0; i < m2->_rows; ++i)
    {
        for (int j = 0; j < m2->_cols; ++j)
            m2->_data[i][j] = ++count;
    }

    printMatrix(m2);

    MATRIX *m3 = createIdentityMatrix(3);
    printMatrix(m3);

    MATRIX *m4 = createMatrix(4, 2);

    int arr[] = {1, 2,
                 3, 4,
                 5, 6,
                 7, 8
                };

    initMatrix(m4, arr);

    printMatrix(m4);

    MATRIX *m5 = transpose(m4);

    printMatrix(m5);

    MATRIX *m6 = concatMatrices(m2, m3);
    printMatrix(m6);

    swapRows(m6, 0, 1);

    printMatrix(m6);

    MATRIX *m7 = addMatrices(m2, m3);
    printMatrix(m7);

    destroyMatrix(m7);
    destroyMatrix(m6);
    destroyMatrix(m5);
    destroyMatrix(m4);
    destroyMatrix(m3);
    destroyMatrix(m2);

    return 0;
}
