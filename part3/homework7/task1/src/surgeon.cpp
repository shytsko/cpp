#include "surgeon.h"
#include "point.h"
#include <iostream>

void scalpel(const Point &pointBegin, const Point &pointEnd) {
  std::cout << "A cut is made with a scalpel from point " << pointBegin
            << " to point " << pointEnd << std::endl;
}

void hemostat(const Point &point) {
  std::cout << "Hemostat applied at point " << point << std::endl;
}
void tweezer(const Point &point) {
  std::cout << "Tweezer applied at point " << point << std::endl;
}
void suture(const Point &pointBegin, const Point &pointEnd) {
  std::cout << "A suture has been placed from point " << pointBegin
            << " to point " << pointEnd << std::endl;
}