#ifndef WINDOW_H
#define WINDOW_H

#include "display.h"
#include "vector2D.h"

class Window
{
    Vector2D position;
    int width;
    int height;
    Display *parent = nullptr;

public:
    Window(Vector2D _position, int _width, int _height);
    Vector2D getPosition(void);
    int getWidth(void);
    int getHeight(void);
    void setParent(Display *_parent);
    void move(Vector2D offset);
    void resize(int _width, int _height);
};
#endif