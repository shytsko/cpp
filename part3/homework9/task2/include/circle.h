#ifndef H_CIRCLE
#define H_CIRCLE

#include "rectangle.h"
#include "shape.h"

class Circle : public Shape {
  double radius;

public:
  Circle(Coordinate inCenter, Color inColor, double inRadius);
  double getRadius(void);
  double getArea(void);
  Rectangle getCircumscribingRectangle(void);
};

#endif