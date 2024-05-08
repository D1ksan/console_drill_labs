#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {

public:
    virtual void Scale(float scaleVector) = 0;

    virtual void ShowInfo() = 0;

    virtual std::string GetName() = 0;

};

#endif // SHAPE_H