#include <iostream>
#include <windows.h>  // Sleep()
#include <ctime>  // для инициализации генератора случайных чисел, 
#include <cstdlib>  //для генерации случайных чисел и их модуля, std::rand и std::abs

using namespace std;

// класс для представленя двумерной точки, расчитыват расстояние до другой точки
class Point2D {
public:
    int x;
    int y;
    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
    void move(int dx, int dy) {  // Метод для перемещения точки на указанные значения по осям
        x += dx;
        y += dy;
    }
    int distanceTo(const Point2D& other) const {  // Метод для вычисления расстояния между точками
        return static_cast<int>(sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)));
    }
};