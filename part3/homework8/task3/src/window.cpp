#include "window.h"
#include "display.h"
#include "vector2D.h"

Window::Window(Vector2D _position, int _width, int _height)
{
    position = _position;
    width = _width;
    height = _height;
}

Vector2D Window::getPosition(void) { return position; }

int Window::getWidth(void) { return width; }

int Window::getHeight(void) { return height; }

void Window::setParent(Display *_parent)
{
    parent = _parent;
}

void Window::move(Vector2D offset)
{
    Vector2D newPosition = position + offset;
    if (newPosition.getX() < 0)
        newPosition.setX(0);

    if (newPosition.getY() < 0)
        newPosition.setY(0);

    if (newPosition.getX() + width > parent->getWidth())
        newPosition.setX(parent->getWidth() - width);

    if (newPosition.getY() + height > parent->getHeight())
        newPosition.setY(parent->getHeight() - height);

    position = newPosition;
}

void Window::resize(int _width, int _height)
{
    if (position.getX() + _width > parent->getWidth())
        _width = parent->getWidth() - position.getX();

    if (position.getY() + _height > parent->getHeight())
        _height = parent->getHeight() - position.getY();

    width = _width;
    height = _height;
}