#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> // Для использования std::find_if

// Структура для представления записи о книге
struct Book {
    std::string id;
    std::string author;
    std::string title;
    int pages;

    // Вывод информации о книге
    void print() const {
        std::cout << std::left << std::setw(10) << id << std::setw(20) << author << std::setw(30) << title << std::setw(10) << pages << std::endl;
    }
};

// Функция для чтения каталога книг из файла
std::vector<Book> readCatalog(const std::string& filename) {
    std::vector<Book> catalog;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return catalog;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("ID") != std::string::npos) // Пропускаем заголовок
            continue;

        std::stringstream ss(line);
        Book book;
        ss >> book.id >> book.author >> book.title >> book.pages;
        catalog.push_back(book);
    }

    file.close();
    return catalog;
}

// Функция для записи каталога книг в файл
void writeCatalog(const std::string& filename, const std::vector<Book>& catalog) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    file << std::setw(10) << "ID" << std::setw(20) << "Author" << std::setw(30) << "Title" << std::setw(10) << "Pages" << std::endl;
    for (const auto& book : catalog) {
        file << std::left << std::setw(10) << book.id << std::setw(20) << book.author << std::setw(30) << book.title << std::setw(10) << book.pages << std::endl;
    }

    file.close();
}
