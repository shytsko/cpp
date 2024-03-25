#ifndef H_RECTANGLE
#define H_RECTANGLE

#include "shape.h"
#include <string>

class Rectangle : public Shape
{
  double sideALength;
  double sideBLength;

public:
  Rectangle(Coordinate inCenter, Color inColor, double inSideALength,
            double inSideBLength);
  double getSideALength(void) const;
  double getSideBLength(void) const;
  virtual double getArea(void) const override;
  virtual Rectangle getCircumscribingRectangle(void) const override;
  Coordinate getLeftDownCoordinate(void) const;
  Coordinate getRightUpCoordinate(void) const;
  virtual std::string getShapeType(void) const override;
};

#endif