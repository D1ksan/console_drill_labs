#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Пример класса Matrix для демонстрации
class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(const std::vector<std::vector<int>>& data) : data(data) {}

    void print() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    // Функция для записи матрицы в текстовый файл
    void writeToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return;
        }

        for (const auto& row : data) {
            for (int val : row) {
                file << val << " ";
            }
            file << std::endl; // Добавляем разделитель
        }

        file.close();
    }

    // Функция для чтения матриц из текстового файла
    static std::vector<Matrix> readFromFile(const std::string& filename) {
        std::vector<Matrix> matrices;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return matrices;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::vector<int> row;
            std::istringstream iss(line);
            int val;
            while (iss >> val) {
                row.push_back(val);
            }
            matrices.emplace_back(Matrix({row}));
        }

        file.close();
        return matrices;
    }
};

int main() {
    // Создаем несколько матриц для записи
    std::vector<Matrix> matrices;
    matrices.emplace_back(Matrix({{1, 2, 3}, {4, 5, 6}}));
    matrices.emplace_back(Matrix({{7, 8, 9}, {10, 11, 12}}));

    // Записываем матрицы в текстовый файл
    for (size_t i = 0; i < matrices.size(); ++i) {
        std::string filename = "matrix_" + std::to_string(i) + ".txt";
        matrices[i].writeToFile(filename);
    }

    // Читаем матрицы из текстового файла
    std::vector<Matrix> readMatrices;
    for (size_t i = 0; i < matrices.size(); ++i) {
        std::string filename = "matrix_" + std::to_string(i) + ".txt";
        auto tempMatrices = Matrix::readFromFile(filename);
        readMatrices.insert(readMatrices.end(), tempMatrices.begin(), tempMatrices.end());
    }

    // Печатаем считанные матрицы
    for (const auto& matrix : readMatrices) {
        matrix.print();
        std::cout << std::endl;
    }

    return 0;
}