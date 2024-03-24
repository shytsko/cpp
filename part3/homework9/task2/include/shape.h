#ifndef H_SHAPE
#define H_SHAPE

#include "coordinate.h"

enum class Color { None = 0, Red = 1, Blue = 2, Green = 3 };

class Shape {
  Coordinate center{0, 0};
  Color color = Color::None;

public:
  Shape(Coordinate inCenter, Color inColor);
  Coordinate getCenter(void);
  Color getColor(void);
};

#endif