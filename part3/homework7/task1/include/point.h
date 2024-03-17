#pragma once
#include <iostream>

struct Point {
  int x = 0;
  int y = 0;
};

std::ostream &operator<<(std::ostream &os, const Point &point);
std::istream &operator>>(std::istream &in, Point &point);
bool operator==(const Point &point1, const Point &point2);
bool operator!=(const Point &point1, const Point &point2);