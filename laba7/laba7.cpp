#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <memory>

int main() {

    // create вектор и список размером 1000 el-s для затрат памяти 
    std::vector<int> vec(1000);
    std::list<int> lst(1000);
    // Вычисляем затраты памяти
    std::cout << "Memory used by vector: " << sizeof(vec) + vec.capacity() * sizeof(int) << " bytes\n";

    std::cout << "Memory used by list: " << sizeof(lst) + lst.size() * (sizeof(int) + 2 * sizeof(void*)) << " bytes\n\n";
    // demonstration производительности операции вставки в начало коллекций
    
    auto start = std::chrono::high_resolution_clock::now(); // Запуск таймера перед операцией
    for (int i = 0; i < 100000; ++i) { 
        vec.insert(vec.begin(), i);
    }
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> vec_time = end - start; // Вычисление времени выполнения операции
    
    std::cout << "------------- Time complexity ---------------\n";
    std::cout << "For 100,000 insertions at the beginning:\n" << std::endl;
    std::cout << "Vector --- " << vec_time.count() << " seconds\n"; 

    start = std::chrono::high_resolution_clock::now(); 
    // Перезапуск таймера перед следующей операцией
    for (int i = 0; i < 100000; ++i) { 
        lst.insert(lst.begin(), i);
    }
    end = std::chrono::high_resolution_clock::now(); 
    
    std::chrono::duration<double> lst_time = end - start; 
    std::cout << "List --- " << lst_time.count() << " seconds\n"; // Вывод времени выполнения операции вставки в список
    std::cout << "List is faster by " << (lst_time / vec_time) * 100 << "%\n"; 
    return 0;
}