#ifndef H_TRIANGLE
#define H_TRIANGLE

#include "rectangle.h"
#include "shape.h"

class Triangle : public Shape {
  double sideLength;

public:
  Triangle(Coordinate inCenter, Color inColor, double inSideLength);
  double getSideLength(void);
  double getArea(void);
  Rectangle getCircumscribingRectangle(void);
};

#endif