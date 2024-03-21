#ifndef DISPLAY_H
#define DISPLAY_H

#include "window.h"

class Display
{
    int width;
    int height;
    Window *window;

public:
    Display(int _width, int _height);
    void addWindow(Window *window);
    void render(void);
    int getWidth(void);
    int getHeight(void);
};
#endif