#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix<int> mat(10, 10, 3);

    std::cout << mat.size() << std::endl;
    std::cout << mat(9, 9) << std::endl;
    std::cout << mat(0, 0) << std::endl;
    return 0;
}
