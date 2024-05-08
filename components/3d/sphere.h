#include "./shape-3d.h"
#include <math.h>

class Sphere : public Shape3D {

private:
	float radius;

	void CalculateVolume() override {
		volume = ((3 / 4) * M_PI * radius * radius * radius);
	}

public:
	Sphere( float radius_ ) {
		radius = radius_;
		CalculateVolume();
	}

	void Scale( float ScaleFactor ) override {
		radius *= ScaleFactor;
		CalculateVolume();
	}

	void ShowInfo() override {
		std::cout << "I'am a sphere!" << std::endl << 
            "My radius is " << radius << std::endl << 
            "My volume is " << volume << std::endl;
	}

	std::string GetName() override {
		return "Sphere";
	}
};