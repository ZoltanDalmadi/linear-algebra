#include "CMatrix.h"

int main()
{
    MATRIX *m = createMatrix(2, 2);
    m->_data[0][1] = 7;
    printMatrix(m);

    printf("\n");

    MATRIX *m2 = createMatrix(3, 3);
    m2->_data[1][1] = 8;
    printMatrix(m2);

    printf("\n");

    MATRIX *m3 = createIdentityMatrix(4);
    printMatrix(m3);

    destroyMatrix(m3);
    destroyMatrix(m2);
    destroyMatrix(m);

    return 0;
}
