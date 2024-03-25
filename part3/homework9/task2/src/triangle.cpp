#include "triangle.h"
#include "rectangle.h"
#include <cmath>

Triangle::Triangle(Coordinate inCenter, Color inColor, double inSideLength)
    : Shape(inCenter, inColor)
{
  sideLength = inSideLength;
}

double Triangle::getSideLength(void) const { return sideLength; }

double Triangle::getArea(void) const
{
  return sideLength * sideLength * std::sqrt(3) / 4;
}

Rectangle Triangle::getCircumscribingRectangle(void) const
{
  return Rectangle(this->getCenter(), Color::None, sideLength,
                   sideLength * std::sqrt(3) / 2);
}

std::string Triangle::getShapeType(void) const
{
  return "Triangle";
}