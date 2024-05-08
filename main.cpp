#include "./tests/square_test.cpp"
#include "./tests/circle_test.cpp"
#include "./tests/triangle_test.cpp"
#include "./tests/cylinder_test.cpp"
#include "./tests/sphere_test.cpp"
#include "./tests/pyramid_test.cpp"

int main() {
    testSquare();
    testCircle();
    testTriangle();
    testCylinder();
    testSphere();
    testPyramid();
    
    return 0;
}