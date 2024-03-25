#include "rectangle.h"

Rectangle::Rectangle(Coordinate inCenter, Color inColor, double inSideALength,
                     double inSideBLength)
    : Shape(inCenter, inColor)
{
  sideALength = inSideALength;
  sideBLength = inSideBLength;
}

double Rectangle::getSideALength(void) const { return sideALength; }

double Rectangle::getSideBLength(void) const { return sideBLength; }

double Rectangle::getArea(void) const { return sideALength * sideBLength; }

Rectangle Rectangle::getCircumscribingRectangle(void) const { return *this; }

Coordinate Rectangle::getLeftDownCoordinate(void) const
{
  return {getCenter().x - sideALength / 2, getCenter().y - sideBLength / 2};
}

Coordinate Rectangle::getRightUpCoordinate(void) const
{
  return {getCenter().x + sideALength / 2, getCenter().y + sideBLength / 2};
}

std::string Rectangle::getShapeType(void) const
{
  return "Rectangle";
}