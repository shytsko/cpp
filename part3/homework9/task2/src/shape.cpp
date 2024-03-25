#include "shape.h"

Shape::Shape(Coordinate inCenter, Color inColor)
{
  center = inCenter;
  color = inColor;
}

Coordinate Shape::getCenter(void) const { return center; }

Color Shape::getColor(void) const { return color; }