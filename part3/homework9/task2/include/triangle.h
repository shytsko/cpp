#ifndef H_TRIANGLE
#define H_TRIANGLE

#include "rectangle.h"
#include "shape.h"

class Triangle : public Shape
{
  double sideLength;

public:
  Triangle(Coordinate inCenter, Color inColor, double inSideLength);
  double getSideLength(void) const;
  virtual double getArea(void) const override;
  virtual Rectangle getCircumscribingRectangle(void) const override;
  virtual std::string getShapeType(void) const override;
};

#endif