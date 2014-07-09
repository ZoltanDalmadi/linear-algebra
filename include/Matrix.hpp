#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <valarray>

template <typename T>
class Matrix
{
public:
    // initializes to zero matrix
    Matrix();
    Matrix(size_t, size_t);
    virtual ~Matrix();

    // access items
    T& operator()(size_t, size_t);

private:
    size_t _rows;
    size_t _cols;
    std::valarray<T> data;
};

template <typename T>
Matrix<T>::Matrix() : _rows(0), _cols(0), data()
{
}

template <typename T>
Matrix<T>::Matrix(size_t row, size_t col) :
    _rows(row), _cols(col), data(_rows * _cols)
{
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col)
{
    if (data.size() > 0 && row <= _rows && col <= _cols)
        return data[row * _cols + row];
}

#endif /* end of include guard: MATRIX_HPP */
