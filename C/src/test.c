#include "CMatrix.h"

int main()
{
    MATRIX *m = createMatrix(2, 2);
    m->_data[0][1] = 7;
    printMatrix(m);

    MATRIX *m2 = createMatrix(3, 3);
    m2->_data[1][1] = 8;
    printMatrix(m2);

    MATRIX *m3 = createIdentityMatrix(4);
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

    destroyMatrix(m5);
    destroyMatrix(m4);
    destroyMatrix(m3);
    destroyMatrix(m2);
    destroyMatrix(m);

    return 0;
}
