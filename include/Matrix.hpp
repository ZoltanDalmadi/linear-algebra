#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <valarray>
#include <exception>

class SimpleException : public std::exception
{
private:
    const char* message;

public:
    SimpleException(const char* msg) throw() : message(msg) {}
    virtual ~SimpleException() {}
    virtual const char* what() const throw()
    {
        return message;
    }
};

template <typename T>
class Matrix
{
public:
    // initialize to empty matrix
    Matrix();

    // initialize to zero matrix
    Matrix(size_t, size_t);

    // initialize all items to a value
    Matrix(size_t, size_t, const T&);

    // initialize with array
    Matrix(size_t, size_t, const T*);

    // initialize with initializer list
    Matrix(size_t, size_t, const std::initializer_list<T>&);

    virtual ~Matrix();

    Matrix<T> operator-() const;

    Matrix<T> operator+(const Matrix<T>&) const;
    Matrix<T>& operator+=(const Matrix<T>&);
    Matrix<T> operator-(const Matrix<T>&) const;
    Matrix<T>& operator-=(const Matrix<T>&);

    // access items
    T& operator()(size_t, size_t);

    // prints out the matrix to a stream
    void printMatrix(std::ostream&);

    Matrix<T> transpose();

    // returns matrix size
    size_t size() const;

protected:
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
Matrix<T>::Matrix(size_t row, size_t col, const T& value) :
    _rows(row), _cols(col), data(value, _rows * _cols)
{
}

template <typename T>
Matrix<T>::Matrix(size_t row, size_t col, const T* value) :
    _rows(row), _cols(col), data(value, _rows * _cols)
{
}

template <typename T>
Matrix<T>::Matrix(size_t row, size_t col,
                  const std::initializer_list<T>& values) :
    _rows(row), _cols(col), data(values)
{
}

template <typename T>
Matrix<T>::~Matrix()
{
}

template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
    Matrix<T> result(*this);
    result.data = -result.data;
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const
{
    Matrix<T> result(*this);
    result += rhs;
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
    if (rhs._rows == _rows && rhs._cols == _cols)
        this->data += rhs.data;
    else
        throw SimpleException("Only equal sized matrices can be added!");

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const
{
    Matrix<T> result(*this);
    result -= rhs;
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
{
    if (rhs._rows == _rows && rhs._cols == _cols)
        this->data -= rhs.data;
    else
        throw SimpleException("Only equal sized matrices can be subtracted!");

    return *this;
}

template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col)
{
    if (data.size() > 0 && row < _rows && col < _cols)
        return data[row * _cols + col];
    else
        throw SimpleException("Index out of range!");
}

template <typename T>
void Matrix<T>::printMatrix(std::ostream& os)
{
    T streamWidth = std::to_string(this->data.max()).size();

    for (size_t i = 0; i < _rows; ++i)
    {
        os << "|";

        for (size_t j = 0; j < _cols; ++j)
        {
            os.width(streamWidth);
            os << this->data[i * _cols + j];

            if (j == _cols - 1)
                os << "|" << std::endl;
            else
                os << " ";
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T>& obj)
{
    obj.printMatrix(os);
    return os;
}

template <typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> trans(_cols, _rows);

    for (size_t n = 0; n < this->_cols * _rows; ++n)
    {
        int i = n / _rows;
        int j = n % _rows;
        trans.data[n] = this->data[_cols * j + i];
    }

    return trans;
}

template <typename T>
inline size_t Matrix<T>::size() const
{
    return data.size();
}

#endif /* end of include guard: MATRIX_HPP */
