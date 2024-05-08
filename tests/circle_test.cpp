#include "./../components/2d/circle.h"

void testCircle() {
    Circle circle(3);
    std::cout << "Testing Circle class:" << std::endl;
    circle.ShowInfo();
    circle.Scale(2);
    circle.ShowInfo();
    std::cout << "\n" << std::endl;
}