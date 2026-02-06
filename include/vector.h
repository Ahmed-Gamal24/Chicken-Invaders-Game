#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class clsVector
{
private:
    float x;
    float y;

public:
    void setX(float x);
    float getX();

    void setY(float y);
    float getY();

    clsVector();
    clsVector(float x, float y);

    void normalize();
};

#endif
