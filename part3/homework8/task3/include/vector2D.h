#pragma once

class Vector2D {
  int x = 0;
  int y = 0;

public:
  Vector2D(void);
  Vector2D(int _x, int _y);
  int getX(void);
  int getY(void);
  void setX(int _x);
  void setY(int _y);
  Vector2D operator+(const Vector2D &vector) const;
};
