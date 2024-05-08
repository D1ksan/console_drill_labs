#include "./shape-3d.h"
#include "./../2d/circle.h"
#include <math.h>

class Cylinder : public Shape3D {

private:
	Circle baseCircle;
	float height;

	void CalculateVolume() override {
		volume = baseCircle.GetArea() * height;
	}

public:
	Cylinder( float radius, float height_ ) : baseCircle( radius ) {
		height = height_;
		CalculateVolume();
	}

	void Scale( float scaleFactor ) override {
		baseCircle.Scale(scaleFactor);
		height *= scaleFactor;
		CalculateVolume();
	}

	void ShowInfo() override {
		std::cout << "I'am a cyllinder!" << std::endl << 
            "My radius is " << std::sqrt( baseCircle.GetArea() / M_PI ) << std::endl << 
            "My height is " << height << std::endl << 
            "My volume is " << volume << std::endl;
	}

	std::string GetName() override { 
        return "Cylinder"; 
    }
};