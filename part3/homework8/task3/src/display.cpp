#include "display.h"
#include "window.h"
#include <iostream>

Display::Display(int _width, int _height)
{
    if (_width < 0)
        _width = 80;
    if (_height < 0)
        _height = 50;
    width = _width;
    height = _height;
}

void Display::addWindow(Window *_window)
{
    window = _window;
    window->setParent(this);
}

void Display::render(void)
{
    char buffer[height][width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            buffer[i][j] = '0';

    for (int i = 0; i < window->getHeight(); i++)
        for (int j = 0; j < window->getWidth(); j++)
            buffer[window->getPosition().getY() + i][window->getPosition().getX() + j] = '1';

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << buffer[i][j];
        std::cout << std::endl;
    }
}

int Display::getWidth(void) { return width; }
int Display::getHeight(void) { return height; }