#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "./../shape.h"

class Shape2D : public Shape {

private:
    virtual void CalculateArea() = 0;

protected:
    float area;

public:
    Shape2D() {
        area = 0;
    };

    float GetArea() {
        return area;
    };

    bool operator>( Shape2D &other ) {
        return area > other.area;
    };

    bool operator<( Shape2D &other ) {
        return area < other.area;
    };

    bool operator==( Shape2D& other ) {
        return area == other.area;
    };

};
#endif // SHAPE2D_H