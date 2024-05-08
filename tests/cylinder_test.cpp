#include "./../components/3d/cylinder.h"

void testCylinder() {
    Cylinder cyl(3, 10);
    std::cout << "Testing Cylinder class:" << std::endl;
    cyl.ShowInfo();
    cyl.Scale(2);
    cyl.ShowInfo();

    Cylinder cyl_smaller(2, 5);
    std::cout << "Cylinder is bigger than smaller one: " << (cyl > cyl_smaller) << std::endl;
    std::cout << "Smaller one is smaller: " << (cyl_smaller < cyl) << std::endl;
    std::cout << "Are they equal: " << (cyl == cyl_smaller) << "\n" << std::endl;
}