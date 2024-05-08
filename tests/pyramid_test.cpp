#include "./../components/3d/triangular-pyramid.h"

void testPyramid() {
    TriangularPyramid piram(3, 7);
    std::cout << "Testing Triangular Pyramid class:" << std::endl;
    piram.ShowInfo();
    piram.Scale(2);
    piram.ShowInfo();
}