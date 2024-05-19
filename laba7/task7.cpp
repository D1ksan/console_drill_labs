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
