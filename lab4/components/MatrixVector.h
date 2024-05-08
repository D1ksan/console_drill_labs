#ifndef MATRIXVECTOR_H
#define MATRIXVECTOR_H

#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
    T** data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int m, unsigned int n);
    ~Matrix();

    T* operator[](int i);

    void fillRandom();

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

    void printSize() const;
    bool isEqual(const Matrix& other) const;

    Matrix& operator+=(const Matrix& matrix);
    Matrix operator+(const Matrix& matrix) const;
    Matrix& operator-=(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix) const;
    Matrix& operator*=(const Matrix& matrix);
    Matrix operator*(const Matrix& matrix) const;

    bool operator!=(const Matrix& matrix) const;
    bool operator==(const Matrix& matrix) const;
};

template <typename T>
class Vector {
private:
    T* data;
    unsigned int size;

public:
    Vector(unsigned int size);
    ~Vector();

    T dotProduct(const Vector& other) const;
    T scalarProduct(const Vector& other) const;

    void fillRandom();
    void printSize() const;
    bool isEqual(const Vector& other) const;
};

 // Включаем реализацию шаблонных классов

#endif // MATRIXVECTOR_H