#include "display.h"
#include "window.h"
#include <iostream>

Display::Display(unsigned _width, unsigned _height) {
  width = _width;
  height = _height;
  window = nullptr;
}

void Display::addWindow(Window *_window) { window = _window; }

void Display::render(void) {
  char *buffer = new char[height * width];
  for (unsigned i = 0; i < height; i++)
    for (unsigned j = 0; j < width; j++)
      buffer[i * width + j] = '0';

  for (unsigned i = (unsigned)window->getPosition().getY();
       i < (unsigned)window->getPosition().getY() + window->getHeight(); i++)
    for (unsigned j = (unsigned)window->getPosition().getX();
         j < (unsigned)window->getPosition().getX() + window->getWidth(); j++)
      buffer[i * width + j] = '1';

  for (unsigned i = 0; i < height; i++) {
    for (unsigned j = 0; j < width; j++)
      std::cout << buffer[i * width + j];
    std::cout << std::endl;
  }

  delete[] buffer;
}

unsigned Display::getWidth(void) { return width; }
unsigned Display::getHeight(void) { return height; }