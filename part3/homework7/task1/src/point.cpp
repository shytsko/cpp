#include "point.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Point &point) {
  return os << '(' << point.x << "; " << point.y << ')';
}

std::istream &operator>>(std::istream &in, Point &point) {
  in >> point.x >> point.y;
  return in;
}

bool operator==(const Point &point1, const Point &point2) {
  return (point1.x == point2.x && point1.y == point2.y);
}

bool operator!=(const Point &point1, const Point &point2) {
  return !(point1 == point2);
}