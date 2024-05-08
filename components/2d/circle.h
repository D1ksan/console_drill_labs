#ifndef CIRCLE_H
#define CIRCLE_H

#include "./shape-2d.h"
#include <math.h>

class Circle : public Shape2D {

private:
	void CalculateArea() override {
		area = M_PI * radius * radius;
	}
    
protected:
	float radius = 1;

public:
	Circle( float radius_ ) {
		radius = radius_;
		CalculateArea();
	}

	void Scale( float ScaleFactor ) override {
		radius *= ScaleFactor;
		CalculateArea();
	}

	void ShowInfo() override {
		std::cout << "I'am a circle!" << std::endl << 
            "My radius is " << radius << std::endl << 
            "My area is " << area << std::endl;
	}

	std::string GetName() override {
		return "Circle";
	}
};
#endif // CIRCLE_H