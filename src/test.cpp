#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix<int> mat(7, 9);

    std::cout << mat.size() << std::endl;
    return 0;
}
