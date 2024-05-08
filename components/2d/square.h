#include "./shape-2d.h"

class Square : public Shape2D {

private:
	float side;

	void CalculateArea() override {
		area = side * side;
	}

public:
	Square( float side_ ) {
		side = side_;
		CalculateArea();
	}

	void Scale( float ScaleFactor ) override {
		side *= ScaleFactor;
		CalculateArea();
	}

	void ShowInfo() override {
		std::cout << "I'am a square!" << std::endl <<
            "My side is " << side << std::endl <<
            "My area is " << area << std::endl;
	}

	std::string GetName() override {
		return "Square";
	}

};