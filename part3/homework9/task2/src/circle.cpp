#include "circle.h"
#include "rectangle.h"
#include <cmath>

Circle::Circle(Coordinate inCenter, Color inColor, double inRadius)
    : Shape(inCenter, inColor)
{
  radius = inRadius;
}

double Circle::getRadius(void) const { return radius; }

double Circle::getArea(void) const { return atan(1.0) * 4 * radius * radius; }

Rectangle Circle::getCircumscribingRectangle(void) const
{
  return Rectangle(this->getCenter(), Color::None, radius * 2, radius * 2);
}

std::string Circle::getShapeType(void) const
{
  return "Circle";
}