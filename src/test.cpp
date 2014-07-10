#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    // Matrix<int> mat1;
    // std::cout << "Matrix1 size: " << mat1.size() << std::endl;
    Matrix<int> mat2(8, 8);
    std::cout << "Matrix2: " << std::endl << std::endl << mat2 << std::endl;
    Matrix<int> mat3(10, 10, 666);
    std::cout << "Matrix3: " << std::endl << std::endl << mat3 << std::endl;

    int arr[] =
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<int> mat4(3, 3, arr);
    std::cout << "Matrix4: " << std::endl << std::endl << mat4 << std::endl;

    Matrix<int> mat5(3, 3,
    {
        0, 0, 5,
        4, 6, 12,
        7, 8, 3
    });

    std::cout << "Matrix5: " << std::endl << std::endl << mat5 << std::endl;

    return 0;
}
