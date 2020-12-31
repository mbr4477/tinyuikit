#include "Box.h"
using namespace ui;

Box::Box(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
    : x(x), y(y), width(width), height(height)
{
}

unsigned int Box::getX()
{
    return x;
}

unsigned int Box::getY()
{
    return y;
}

unsigned int Box::getWidth()
{
    return width;
}

unsigned int Box::getHeight()
{
    return height;
}

Box Box::offsetBy(Box other)
{
    return Box(x + other.getX(), y + other.getY(), width, height);
}