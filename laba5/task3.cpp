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

// Функция для добавления новой записи в каталог
void addBook(std::vector<Book>& catalog) {
    Book book;
    std::cout << "Enter book ID: ";
    std::cin >> book.id;
    std::cout << "Enter author name: ";
    std::cin.ignore();
    std::getline(std::cin, book.author);
    std::cout << "Enter book title: ";
    std::getline(std::cin, book.title);
    std::cout << "Enter number of pages: ";
    std::cin >> book.pages;
    catalog.push_back(book);
}

// Функция для просмотра всех записей каталога
void viewCatalog(const std::vector<Book>& catalog) {
    std::cout << std::setw(10) << "ID" << std::setw(20) << "Author" << std::setw(30) << "Title" << std::setw(10) << "Pages" << std::endl;
    for (const auto& book : catalog) {
        book.print();
    }
}

// Функция для удаления записи из каталога по ID
void deleteBook(std::vector<Book>& catalog, const std::string& id) {
    auto it = std::find_if(catalog.begin(), catalog.end(), [&id](const Book& book) { return book.id == id; });
    if (it != catalog.end()) {
        catalog.erase(it);
        std::cout << "Book with ID " << id << " has been deleted." << std::endl;
    } else {
        std::cout << "Book with ID " << id << " not found." << std::endl;
    }
}

// Функция для поиска записи в каталоге по ID
void searchBook(const std::vector<Book>& catalog, const std::string& id) {
    auto it = std::find_if(catalog.begin(), catalog.end(), [&id](const Book& book) { return book.id == id; });
    if (it != catalog.end()) {
        std::cout << "Book found:" << std::endl;
        it->print();
    } else {
        std::cout << "Book with ID " << id << " not found." << std::endl;
    }
}

// Функция для редактирования записи в каталоге по ID
void editBook(std::vector<Book>& catalog, const std::string& id) {
    auto it = std::find_if(catalog.begin(), catalog.end(), [&id](const Book& book) { return book.id == id; });
    if (it != catalog.end()) {
        std::cout << "Enter new author name: ";
        std::cin.ignore();
        std::getline(std::cin, it->author);
        std::cout << "Enter new book title: ";
        std::getline(std::cin, it->title);
        std::cout << "Enter new number of pages: ";
        std::cin >> it->pages;
        std::cout << "Book with ID " << id << " has been updated." << std::endl;
    } else {
        std::cout << "Book with ID " << id << " not found." << std::endl;
    }
}

int main() {
    std::vector<Book> catalog = readCatalog("books.txt"); // Считываем каталог из файла

    int choice;
    std::string id;
    do {
        std::cout << "\nMenu:\n1. Add book\n2. View catalog\n3. Delete book\n4. Search book\n5. Edit book\n6. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addBook(catalog);
                break;
            case 2:
                viewCatalog(catalog);
                break;
            case 3:
                std::cout << "Enter ID of book to delete: ";
                std::cin >> id;
                deleteBook(catalog, id);
                break;
            case 4:
                std::cout << "Enter ID of book to search: ";
                std::cin >> id;
                searchBook(catalog, id);
                break;
            case 5:
                std::cout << "Enter ID of book to edit: ";
                std::cin >> id;
                editBook(catalog, id);
                break;
            case 6:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 6." << std::endl;
                break;
        }
    } while (choice != 6);

    writeCatalog("books.txt", catalog); // Записываем каталог в файл перед выходом

    return 0;
}