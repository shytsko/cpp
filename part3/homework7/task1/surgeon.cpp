#include "surgeon.h"
#include <iostream>

void scalpel(const Point &pointBegin, const Point &pointEnd)
{
    std::cout << "A cut is made with a scalpel from point (" << pointBegin.x << ", " << pointEnd.y
              << ") to point (" << pointEnd.x << ", " << pointEnd.y << ")" << std::endl;
}