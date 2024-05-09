#include <iostream>
#include <fstream>
#include <string>

int countWordOccurrences(const std::string& filename, const std::string& word) {
    std::ifstream file(filename); // Открытие файла для чтения
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line)) { // Построчное чтение файла
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != std::string::npos) { // Поиск слова в текущей строке
            ++count;
            pos += word.length(); // Переход к следующему символу после найденного слова
        }
    }

    file.close(); // Закрытие файла
    return count;
}

int main() {
    std::string filename = "textfile.txt"; // Имя текстового файла
    std::string word = "example"; // Заданное слово для поиска

    int occurrences = countWordOccurrences(filename, word);
    if (occurrences != -1) {
        std::cout << "The word '" << word << "' appears " << occurrences << " times in the file." << std::endl;
    }

    return 0;
}