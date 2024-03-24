#ifndef H_RECTANGLE
#define H_RECTANGLE

#include "shape.h"

class Rectangle : public Shape {
  double sideALength;
  double sideBLength;

public:
  Rectangle(Coordinate inCenter, Color inColor, double inSideALength,
            double inSideBLength);
  double getSideALength(void);
  double getSideBLength(void);
  double getArea(void);
  Rectangle getCircumscribingRectangle(void);
  Coordinate getLeftDownCoordinate(void);
  Coordinate getRightUpCoordinate(void);
};

#endif