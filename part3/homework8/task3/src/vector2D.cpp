#include "vector2D.h"

Vector2D::Vector2D(void) {
  x = 0;
  y = 0;
}

Vector2D::Vector2D(int _x, int _y) {
  x = _x;
  y = _y;
}

int Vector2D::getX(void) { return x; }
int Vector2D::getY(void) { return y; }
void Vector2D::setX(int _x) { x = _x; }
void Vector2D::setY(int _y) { y = _y; }

Vector2D Vector2D::operator+(const Vector2D &vector) const {
  return Vector2D{x + vector.x, y + vector.y};
}