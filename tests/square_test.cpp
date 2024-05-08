#include "./../components/2d/square.h"

void testSquare() {
    Square sq(5);
    std::cout << "Testing Square class:" << std::endl;
    sq.ShowInfo();
    sq.Scale(2);
    sq.ShowInfo();
    std::cout << sq.GetName() << std::endl;

    Square sq_smaller(3);
    std::cout << "Square is bigger than smaller one: " << (sq > sq_smaller) << std::endl;
    std::cout << "Smaller one is smaller: " << (sq_smaller < sq) << std::endl;
    std::cout << "Are they equal: " << (sq_smaller == sq) << "\n" << std::endl;
}