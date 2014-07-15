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
    m4->_data[0][0] = 1;
    m4->_data[0][1] = 2;
    m4->_data[1][0] = 3;
    m4->_data[1][1] = 4;
    m4->_data[2][0] = 5;
    m4->_data[2][1] = 6;
    m4->_data[3][0] = 7;
    m4->_data[3][1] = 8;

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
