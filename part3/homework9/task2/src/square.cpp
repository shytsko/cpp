#include "square.h"

Square::Square(Coordinate inCenter, Color inColor, double inSideLength)
    : Rectangle(inCenter, inColor, inSideLength, inSideLength) {}

double Square::getSideLength(void) const { return this->getSideALength(); }

std::string Square::getShapeType(void) const
{
    return "Square";
}