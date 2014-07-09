#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <valarray>

template <typename T>
class Matrix
{
public:
    // initializes to zero matrix
    Matrix();
    virtual ~Matrix();
    T &operator()(size_t, size_t);

private:
    size_t _rows;
    size_t _cols;
    std::valarray<T> data;
};

template <typename T>
Matrix<T><T>::Matrix() : _rows(0), _cols(0), data(T())
{
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
T &Matrix<T>::operator()(size_t col, size_t row)
{
}

#endif /* end of include guard: MATRIX_HPP */
