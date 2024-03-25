#ifndef H_SQUARE
#define H_SQUARE

#include "rectangle.h"
#include "shape.h"

class Square : public Rectangle
{
public:
  Square(Coordinate inCenter, Color inColor, double inSideLength);
  double getSideLength(void) const;
  virtual std::string getShapeType(void) const override;
};

#endif