#ifndef H_CIRCLE
#define H_CIRCLE

#include "rectangle.h"
#include "shape.h"

class Circle : public Shape
{
  double radius;

public:
  Circle(Coordinate inCenter, Color inColor, double inRadius);
  double getRadius(void) const;
  virtual double getArea(void) const override;
  virtual Rectangle getCircumscribingRectangle(void) const override;
  virtual std::string getShapeType(void) const override;
};

#endif