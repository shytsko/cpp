#pragma once
#include "window.h"

class Display {
  unsigned width;
  unsigned height;
  Window *window;

public:
  Display(unsigned _width, unsigned _height);
  void addWindow(Window *window);
  void render(void);
  unsigned getWidth(void);
  unsigned getHeight(void);
};
