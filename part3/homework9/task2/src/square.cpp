#include "square.h"

Square::Square(Coordinate inCenter, Color inColor, double inSideLength)
    : Rectangle(inCenter, inColor, inSideLength, inSideLength) {}

double Square::getSideLength(void) { return this->getSideALength(); }