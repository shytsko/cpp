#include "rectangle.h"

Rectangle::Rectangle(Coordinate inCenter, Color inColor, double inSideALength,
                     double inSideBLength)
    : Shape(inCenter, inColor) {
  sideALength = inSideALength;
  sideBLength = inSideBLength;
}

double Rectangle::getSideALength(void) { return sideALength; }

double Rectangle::getSideBLength(void) { return sideBLength; }

double Rectangle::getArea(void) { return sideALength * sideBLength; }

Rectangle Rectangle::getCircumscribingRectangle(void) { return *this; }

Coordinate Rectangle::getLeftDownCoordinate(void) {
  return {getCenter().x - sideALength / 2, getCenter().y - sideBLength / 2};
}

Coordinate Rectangle::getRightUpCoordinate(void) {
  return {getCenter().x + sideALength / 2, getCenter().y + sideBLength / 2};
}