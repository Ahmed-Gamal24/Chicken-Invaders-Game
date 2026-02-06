#include "../include/vector.h"

void clsVector::setX(float x)
{
    this->x = x;
}

float clsVector::getX()
{
    return this->x;
}

void clsVector::setY(float y)
{
    this->y = y;
}

float clsVector::getY()
{
    return this->y;
}

clsVector::clsVector()
{
}

clsVector::clsVector(float x, float y)
{
    this->x = x;
    this->y = y;
}

void clsVector::normalize()
{
    float magnitude = sqrt((x * x) + (y * y));
    this->x = x / magnitude;
    this->y = y / magnitude;
}
