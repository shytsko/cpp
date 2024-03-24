#include "shape.h"

Shape::Shape(Coordinate inCenter, Color inColor) {
  center = inCenter;
  color = inColor;
}

Coordinate Shape::getCenter(void) { return center; }

Color Shape::getColor(void) { return color; }