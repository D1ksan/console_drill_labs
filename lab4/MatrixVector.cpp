#include "components/MatrixVector.h"
#include <cstdlib>
#include <ctime>

template <typename T>
Matrix<T>::Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
    data = new T*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new T[n];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (unsigned int i = 0; i < m; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
void Matrix<T>::printSize() const {
    std::cout << "Matrix size: " << m << "x" << n << std::endl;
}

template <typename T>
bool Matrix<T>::isEqual(const Matrix& other) const {
    if (m != other.m || n != other.n) {
        return false;
    }
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
T* Matrix<T>::operator[](int i) {
    return data[i];
}

template <typename T>
void Matrix<T>::fillRandom() {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] = rand() % 10;
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (unsigned int i = 0; i < matrix.m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& matrix) {
    if (m != matrix.m || n != matrix.n) {
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] += matrix.data[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& matrix) const {
    Matrix<T> result(m, n);
    result = *this;
    result += matrix;
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& matrix) {
    if (m != matrix.m || n != matrix.n) {
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] -= matrix.data[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& matrix) const {
    Matrix<T> result(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& matrix) {
    if (n != matrix.m) {
        std::cerr << "Matrices must have compatible dimensions for multiplication" << std::endl;
        return *this;
    }
    Matrix<T> result(m, matrix.n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matrix) const {
    if (n != matrix.m) {
        std::cerr << "Matrices must have compatible dimensions for multiplication" << std::endl;
        return Matrix<T>(0, 0);
    }
    Matrix<T> result(m, matrix.n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix<T>& matrix) const {
    if (m != matrix.m || n != matrix.n) {
        return true;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (data[i][j] != matrix.data[i][j]) {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& matrix) const {
    return !(*this != matrix);
}

template <typename T>
Vector<T>::Vector(unsigned int size) : size(size) {
    data = new T[size];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
void Vector<T>::printSize() const {
    std::cout << "Vector size: " << size << std::endl;
}

template <typename T>
bool Vector<T>::isEqual(const Vector& other) const {
    if (size != other.size) {
        return false;
    }
    for (unsigned int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void Vector<T>::fillRandom() {
    for (unsigned int i = 0; i < size; i++) {
        data[i] = rand() % 10;
    }
}

template <typename T>
T Vector<T>::dotProduct(const Vector<T>& other) const {
    if (size != other.size) {
        std::cerr << "Vectors must have the same size" << std::endl;
        return T();
    }

    T result = T();
    for (unsigned int i = 0; i < size; ++i) {
        result += data[i] * other.data[i];
    }
    return result;
}

template <typename T>
T Vector<T>::scalarProduct(const Vector<T>& other) const {
    if (size != other.size) {
        std::cerr << "Vectors must have the same size" << std::endl;
        return T();
    }

    T result = T();
    for (unsigned int i = 0; i < size; ++i) {
        result += data[i] * other.data[i];
    }
    return result;
}