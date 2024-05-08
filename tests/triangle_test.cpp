#include "./../components/2d/triangle.h"

void testTriangle() {
    Triangle tri(3, 5);
    std::cout << "Testing Triangle class:" << std::endl;
    tri.ShowInfo();
    tri.Scale(2);
    tri.ShowInfo();
    std::cout << "\n" << std::endl;
}