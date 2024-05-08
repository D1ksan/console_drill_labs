#include "C:\Users\Alena\projects\console_drill_labs\lab4\components\MatrixVector.h"
#include "C:\Users\Alena\projects\console_drill_labs\lab4\MatrixVector.cpp"
#include <iostream>

int main() {
    // Тестирование класса Matrix
    Matrix<int> mat1(3, 3);
    mat1.fillRandom();
    mat1.printSize();

    Matrix<int> mat2(3, 3);
    mat2.fillRandom();
    mat2.printSize();

    std::cout << "Are mat1 and mat2 equal? " << (mat1.isEqual(mat2) ? "Yes" : "No") << std::endl;

    // Тестирование класса Vector
    Vector<int> vec1(5);
    vec1.fillRandom();
    vec1.printSize();

    Vector<int> vec2(5);
    vec2.fillRandom();
    vec2.printSize();

    std::cout << "Are vec1 and vec2 equal? " << (vec1.isEqual(vec2) ? "Yes" : "No") << std::endl;

    return 0;
}