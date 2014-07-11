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

    //-------------------------------------------------------------------------
    //  CONSTRUCTORS

    // Initialize to empty matrix
    Matrix() : _rows(0), _cols(0), data() {}

    // Initialize to zero matrix
    Matrix(size_t row, size_t col) :
        _rows(row), _cols(col), data(_rows * _cols) {}

    // Initialize all items to a value
    Matrix(size_t row, size_t col, const T& value) :
        _rows(row), _cols(col), data(value, _rows * _cols) {}

    // Initialize with array
    Matrix(size_t row, size_t col, const T* values) :
        _rows(row), _cols(col), data(values, _rows * _cols) {}

    // Initialize with initializer list
    Matrix(size_t row, size_t col, const std::initializer_list<T>& values) :
        _rows(row), _cols(col), data(values) {}

    virtual ~Matrix() {}

    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    // OPERATORS

    // Negate matrix values
    Matrix<T> operator-() const
    {
        Matrix<T> result(*this);
        result.data = -result.data;
        return result;
    }

    // Addition / subtraction
    Matrix<T> operator+(const Matrix<T>& rhs) const
    {
        Matrix<T> result(*this);
        result += rhs;
        return result;
    }

    Matrix<T>& operator+=(const Matrix<T>& rhs)
    {
        if (rhs._rows == _rows && rhs._cols == _cols)
            this->data += rhs.data;
        else
            throw SimpleException("Only equal sized matrices can be added!");

        return *this;
    }

    Matrix<T> operator-(const Matrix<T>& rhs) const
    {
        Matrix<T> result(*this);
        result -= rhs;
        return result;
    }

    inline Matrix<T>& operator-=(const Matrix<T>& rhs)
    {
        return *this += -rhs;
    }

    // Scalar multiplication / division
    Matrix<T> operator*(const T& rhs) const
    {
        Matrix<T> result(*this);
        result *= rhs;
        return result;
    }

    Matrix<T>& operator*=(const T& rhs)
    {
        this->data *= rhs;
        return *this;
    }

    Matrix<T> operator/(const T& rhs) const
    {
        Matrix<T> result(*this);
        result /= rhs;
        return result;
    }

    Matrix<T>& operator/=(const T& rhs)
    {
        this->data /= rhs;
        return *this;
    }

    // Matrix multiplication / division
    Matrix<T> operator*(const Matrix<T>& rhs) const
    {
        if (_rows == rhs._cols && _cols == rhs._rows)
        {
            Matrix<T> result(_rows, rhs._cols);

            for (size_t i = 0; i < _rows; ++i)
            {
                for (size_t j = 0; j < rhs._cols; ++j)
                {
                    T x = (this->getRow(i) * rhs.getCol(j)).sum();
                    result(i, j) = x;
                }
            }

            return result;
        }
        else
            throw SimpleException("Matrix multiplication is not possible!");
    }

    inline Matrix<T> operator/(const Matrix<T>& rhs) const
    {
        return *this * (1 / rhs);
    }

    // Access items
    inline T& operator()(size_t row, size_t col)
    {
        if (data.size() > 0 && row < _rows && col < _cols)
            return data[row * _cols + col];
        else
            throw SimpleException("Index out of range!");
    }

    inline friend std::ostream& operator<<(std::ostream& os, Matrix<T>& m)
    {
        m.printMatrix(os);
        return os;
    }

    friend Matrix<T> operator*(const T& lhs, const Matrix<T>& rhs)
    {
        Matrix<T> result(rhs);
        result.data = lhs * rhs.data;
        return result;
    }

    friend Matrix<T> operator/(const T& lhs, const Matrix<T>& rhs)
    {
        Matrix<T> result(rhs);
        result.data = lhs / rhs.data;
        return result;
    }

    //-------------------------------------------------------------------------

    // Compute transpose of matrix
    Matrix<T> transpose() const
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

    // Returns matrix size
    inline size_t size() const
    {
        return data.size();
    }

    inline std::valarray<T> getRow(const size_t& row) const
    {
        return data[std::slice(row * _cols, _cols, 1)];
    }

    inline std::valarray<T> getCol(const size_t& col) const
    {
        return data[std::slice(col, _rows, _cols)];
    }

    // Prints out the matrix to a stream
    void printMatrix(std::ostream& os)
    {
        // count biggest element's digits
        T streamWidth = std::to_string(std::abs(data).max()).size();

        // if there is a negative item, include the '-' sign's width
        if (data.min() < 0)
            streamWidth++;

        for (size_t i = 0; i < _rows; ++i)
        {
            os << "|";

            for (size_t j = 0; j < _cols; ++j)
            {
                // set to digits of biggest element
                os.width(streamWidth);
                os << this->data[i * _cols + j];

                if (j == _cols - 1)
                    os << "|" << std::endl;
                else
                    os << " ";
            }
        }
    }

protected:
    size_t _rows;
    size_t _cols;
    std::valarray<T> data;
};

// for Matrix<T>::getRows and Matrix<T>::getCols
template <typename T>
std::ostream& operator<<(std::ostream& os, std::valarray<T>& va)
{
    for (auto& i : va)
        os << i << " ";

    return os;
}

// same as above, but for rvalues
template <typename T>
inline std::ostream& operator<<(std::ostream& os, std::valarray<T>&& va)
{
    return os << va;
}

#endif /* end of include guard: MATRIX_HPP */
