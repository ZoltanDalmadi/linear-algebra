#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix<int> mat(4, 4);
    std::cout << mat(1, 1) << std::endl;
    return 0;
}
