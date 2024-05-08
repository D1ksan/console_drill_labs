#include "./../components/3d/sphere.h"

void testSphere() {
    Sphere sphere(5);
    std::cout << "Testing Sphere class:" << std::endl;
    sphere.ShowInfo();
    sphere.Scale(2);
    sphere.ShowInfo();
    std::cout << "\n" << std::endl;
}