#include "CMatrix.h"

int main()
{
    /* MATRIX *m2 = createMatrix(3, 3); */
    /*  */
    /* int count = 0; */
    /*  */
    /* for (int i = 0; i < m2->_rows; ++i) */
    /* { */
    /*     for (int j = 0; j < m2->_cols; ++j) */
    /*         m2->_data[i][j] = ++count; */
    /* } */
    /*  */
    /* printMatrix(m2); */
    /*  */
    /* MATRIX *m3 = createIdentityMatrix(3); */
    /* printMatrix(m3); */
    /*  */
    /* MATRIX *m4 = createMatrix(4, 2); */
    /*  */
    /* int arr[] = {1, 2, */
    /*              3, 4, */
    /*              5, 6, */
    /*              7, 8 */
    /*             }; */
    /*  */
    /* initMatrix(m4, arr); */
    /*  */
    /* printMatrix(m4); */
    /*  */
    /* MATRIX *m5 = transpose(m4); */
    /*  */
    /* printMatrix(m5); */
    /*  */
    /* MATRIX *m6 = concatMatrices(m2, m3); */
    /* printMatrix(m6); */
    /*  */
    /* swapRows(m6, 0, 1); */
    /*  */
    /* printMatrix(m6); */
    /*  */
    /* MATRIX *m7 = addMatrices(m2, m3); */
    /* printMatrix(m7); */
    /*  */
    /* MATRIX *m8 = copyMatrix(m7); */
    /* scalarMultiplyMatrix(m8, 9); */
    /* printMatrix(m8); */
    /*  */
    /* int arr2[] = {1, 0, 2, */
    /*               -1, 3, 1 */
    /*              }; */
    /*  */
    /* MATRIX *m9 = createMatrix(2, 3); */
    /* initMatrix(m9, arr2); */
    /* printMatrix(m9); */
    /*  */
    /* int arr3[] = {3, 1, */
    /*               2, 1, */
    /*               1, 0 */
    /*              }; */
    /*  */
    /* MATRIX *m10 = createMatrix(3, 2); */
    /* initMatrix(m10, arr3); */
    /* printMatrix(m10); */
    /*  */
    /* MATRIX *m11 = multiplyMatrices(m9, m10); */
    /* printMatrix(m11); */
    /*  */
    /* destroyMatrix(m11); */
    /* destroyMatrix(m10); */
    /* destroyMatrix(m9); */
    /* destroyMatrix(m8); */
    /* destroyMatrix(m7); */
    /* destroyMatrix(m6); */
    /* destroyMatrix(m5); */
    /* destroyMatrix(m4); */
    /* destroyMatrix(m3); */
    /* destroyMatrix(m2); */


    /* double arr[] = {1.0, 3.0, 4.0, */
    /*                 -2.0, 5.0, 1.0, */
    /*                 6.0, 0.0, -2.0 */
    /*                }; */

    MATRIX *m1 = createMatrix(1000, 1000);

    for (int i = 0; i < m1->_rows; ++i)
    {
        for (int j = 0; j < m1->_cols; ++j)
            m1->_data[i][j] = rand() % 1000;
    }

    MATRIX *m2 = inverse(m1);
    /* printMatrix(m2); */

    destroyMatrix(m2);
    destroyMatrix(m1);

    return 0;
}
