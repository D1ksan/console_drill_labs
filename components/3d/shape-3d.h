#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "./../shape.h"

class Shape3D : public Shape {

private:
    virtual void CalculateVolume() = 0;

protected:
    float volume;

public:
    Shape3D() {
        volume = 0;
    }

    bool operator<( Shape3D &other ) {
        return volume < other.volume;
    }

    bool operator>( Shape3D &other ) {
        return volume > other.volume;
    }

    bool operator==( Shape3D &other ) {
        return volume == other.volume;
    }
};
#endif // SHAPE3D_H