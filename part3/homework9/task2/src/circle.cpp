#include "circle.h"
#include "rectangle.h"
#include <cmath>

Circle::Circle(Coordinate inCenter, Color inColor, double inRadius)
    : Shape(inCenter, inColor) {
  radius = inRadius;
}

double Circle::getRadius(void) { return radius; }

double Circle::getArea(void) { return atan(1.0) * 4 * radius; }

Rectangle Circle::getCircumscribingRectangle(void) {
  return Rectangle(this->getCenter(), Color::None, radius * 2, radius * 2);
}