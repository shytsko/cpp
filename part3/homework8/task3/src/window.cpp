#include "window.h"
#include "display.h"
#include "vector2D.h"

Window::Window(Vector2D _position, unsigned _width, unsigned _height,
               Display *_parent) {
  position = _position;
  width = _width;
  height = _height;
  parent = _parent;
  parent->addWindow(this);
}

Vector2D Window::getPosition(void) { return position; }

unsigned Window::getWidth(void) { return width; }

unsigned Window::getHeight(void) { return height; }

void Window::move(const Vector2D &offset) {
  Vector2D newPosition = position + offset;
  if (newPosition.getX() < 0)
    newPosition.setX(0);

  if (newPosition.getY() < 0)
    newPosition.setY(0);

  if ((unsigned)newPosition.getX() + width > parent->getWidth())
    newPosition.setX((int)(parent->getWidth() - width));

  if ((unsigned)newPosition.getY() + height > parent->getHeight())
    newPosition.setY((int)(parent->getHeight() - height));

  position = newPosition;
}

void Window::resize(unsigned _width, unsigned _height) {
  if ((unsigned)position.getX() + _width > parent->getWidth())
    _width = parent->getWidth() - (unsigned)position.getX();

  if ((unsigned)position.getY() + _height > parent->getHeight())
    _height = parent->getHeight() - (unsigned)position.getY();

  width = _width;
  height = _height;
}