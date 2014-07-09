#include <iostream>
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    Matrix<int> mat(10, 10, 3);

    std::cout << mat.size() << std::endl;
    std::cout << mat(9, 9) << std::endl;

    try
    {
        std::cout << mat(10, 0) << std::endl;
    }

    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
