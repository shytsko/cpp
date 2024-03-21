#pragma once

// #include "display.h"
#include "vector2D.h"

// #include "display.h" не работает
// Пришлось сделать так
class Display;

class Window {
  Vector2D position;
  unsigned width;
  unsigned height;
  Display *parent;

public:
  Window(Vector2D _position, unsigned _width, unsigned _height,
         Display *_parent);
  Vector2D getPosition(void);
  unsigned getWidth(void);
  unsigned getHeight(void);
  void move(const Vector2D &offset);
  void resize(unsigned _width, unsigned _height);
};
