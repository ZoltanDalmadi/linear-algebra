#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix<double> A(3, 3,
    {
        1, 0, 2,
        -1, 3, 1,
        4, 5, -12
    });

    std::cout << "A:" << std::endl << A << std::endl;

    Matrix<double> B(3, 3,
    {
        3, 1, 6,
        2, 1, 23,
        34, 3, 1
    });

    std::cout << "B:" << std::endl << B << std::endl;

    Matrix<double> C = A * B;

    std::cout << "A * B:" << std::endl << C << std::endl;

    Matrix<double> D = 1.0 / C;

    std::cout << "D:" << std::endl << D << std::endl;

    Matrix<double> E = 9 * D;
    std::cout << "E:" << std::endl << E << std::endl;

    return 0;
}
