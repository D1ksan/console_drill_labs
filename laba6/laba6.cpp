#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // Открытие файла для чтения
    std::ifstream inputFile("Laba6.txt");
    // Проверка открытия файла
    if (!inputFile.is_open()) {
        std::cout << "Error: File is not definded" << std::endl;
        return 1;
    }
    // Инициализация вектора для хранения чисел
    std::vector<int> vector;
    int num;

    while (inputFile >> num) {
        vector.push_back(num);
    }

    std::reverse(vector.begin(), vector.end());
    // Поиск минимального элемента в векторе
    int minElement = *std::min_element(vector.begin(), vector.end());
    std::cout << "Minimum elem: " << minElement << std::endl;
    vector.erase(std::remove_if(vector.begin(), vector.end(), [](int n) { return n % 2 == 0; }), vector.end());

    // Сортировка вектора по возрастанию
    std::sort(vector.begin(), vector.end());
    int newElement = 25;
    vector.insert(std::upper_bound(vector.begin(), vector.end(), newElement), newElement);
    int elementToFind = 3;
    auto it = std::find(vector.begin(), vector.end(), elementToFind);