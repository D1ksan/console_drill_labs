#include "./shape-3d.h"
#include "./../2d/triangle.h"

class TriangularPyramid : public Shape3D {

private:
	float height;
	Triangle baseTriangle;

	void CalculateVolume() override {
		volume = ((1/3) * baseTriangle.GetArea() * height);
	}

public:
	TriangularPyramid( float base_, float height_ ) : baseTriangle( base_, height_ ) {
		height = height_;
		CalculateVolume();
	}

	void Scale( float ScaleFactor ) override {
		height *= ScaleFactor;
		CalculateVolume();
	}

	void ShowInfo() override {
		std::cout << "I'am a triangular Pyramid!" << std::endl << 
            "My height is " << height << std::endl << 
            "My volume is " << volume << std::endl;
	}

	std::string GetName() override {
		return "Triangular Pyramid";
	}
};