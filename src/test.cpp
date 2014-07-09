#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix<int> mat1;
    std::cout << "Matrix1 size: " << mat1.size() << std::endl;
    Matrix<int> mat2(8, 8);
    std::cout << "Matrix2 size: " << mat2.size() << std::endl;
    Matrix<int> mat3(10, 10, 3);
    std::cout << "Matrix3 size: " << mat3.size() << std::endl;

    std::cout << mat2(5, 5) << std::endl;
    std::cout << mat3(9, 7) << std::endl;

    int arr[] =
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix<int> mat4(3, 3, arr);
    std::cout << "Matrix4 size: " << mat4.size() << std::endl;
    std::cout << mat4(2, 2) << std::endl;

    Matrix<int> mat5(3, 3,
    {
        10, 20, 30,
        40, 50, 60,
        70, 80, 90
    });
    std::cout << "Matrix5 size: " << mat5.size() << std::endl;
    std::cout << mat5(2, 2) << std::endl;

    return 0;
}
