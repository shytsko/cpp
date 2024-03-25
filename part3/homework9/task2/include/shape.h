#ifndef H_SHAPE
#define H_SHAPE

#include "coordinate.h"
#include <string>

class Rectangle;

enum class Color
{
  None = 0,
  Red = 1,
  Blue = 2,
  Green = 3
};

class Shape
{
  Coordinate center{0, 0};
  Color color = Color::None;

public:
  Shape(Coordinate inCenter, Color inColor);
  Coordinate getCenter(void) const;
  Color getColor(void) const;
  virtual double getArea(void) const = 0;
  virtual Rectangle getCircumscribingRectangle(void) const = 0;
  virtual std::string getShapeType(void) const = 0;
};

#endif