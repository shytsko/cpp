/*Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний
треугольник, прямоугольник. Для всех этих фигур есть общие поля-данные — это
координаты их центра и условный цвет фигуры: красный, синий или зелёный. Для
отдельных фигур есть и уникальные параметры: радиус для круга, длина ребра для
квадрата и равностороннего треугольника, ширина и высота для прямоугольника. Все
данные — это вещественные числа с удвоенной точностью. Для каждой из фигур
требуется определить метод нахождения площади фигуры, а также метод нахождения
прямоугольника, описывающего фигуру полностью (он может быть больше зоны фигуры,
но не меньше).*/

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"
#include "triangle.h"
#include "coordinate.h"
#include <iostream>

Color inputColor(void)
{
  std::cout << "Select color (1 - red, 2 - blue, 3 - green, other - none) > ";
  int i;
  std::cin >> i;
  return (i >= 1 && i <= 3) ? static_cast<Color>(i) : Color::None;
}

Coordinate inputCoordinate(void)
{
  std::cout << "Enter x and y coordinates separated by spaces > ";
  double x, y;
  std::cin >> x >> y;
  return {x, y};
}

void outputShapeInfo(const Shape *shape)
{
  if (shape == nullptr)
    return;

  std::cout << shape->getShapeType() << std::endl;

  Color color = shape->getColor();

  std::cout << "Color: ";
  switch (color)
  {
  case Color::None:
    std::cout << "None";
    break;
  case Color::Red:
    std::cout << "Red";
    break;
  case Color::Blue:
    std::cout << "Blue";
    break;
  case Color::Green:
    std::cout << "Green";
    break;
  default:
    break;
  }
  std::cout << std::endl
            << "Area: " << shape->getArea() << std::endl;
  Rectangle rectangle = shape->getCircumscribingRectangle();
  Coordinate leftDown = rectangle.getLeftDownCoordinate();
  Coordinate rightUp = rectangle.getRightUpCoordinate();

  std::cout << "Coordinates of the circumscribing rectangle: ("
            << leftDown.x << ", " << leftDown.y << ") (" << rightUp.x << ", " << rightUp.y << ")" << std::endl;
}

int main()
{
  Shape *shape = nullptr;
  ;

  std::string type;
  std::cout << "Enter type of shape (circle, square, triangle, rectangle)> ";
  std::cin >> type;

  Color color = inputColor();
  Coordinate center;
  std::cout << "Coordinates of center. ";
  center = inputCoordinate();

  if (type == "circle")
  {
    double radius;
    std::cout << "Enter radius > ";
    std::cin >> radius;
    shape = new Circle(center, color, radius);
  }
  else if (type == "square" || type == "triangle")
  {
    double sideLength;
    std::cout << "Enter side length > ";
    std::cin >> sideLength;
    if (type == "square")
      shape = new Square(center, color, sideLength);
    else
      shape = new Triangle(center, color, sideLength);
  }
  else if (type == "rectangle")
  {
    double sideALength;
    std::cout << "Enter first side length > ";
    std::cin >> sideALength;
    double sideBLength;
    std::cout << "Enter second side length > ";
    std::cin >> sideBLength;
    shape = new Rectangle(center, color, sideALength, sideBLength);
  }
  else
  {
    std::cout << "Unknown figure type" << std::endl;
  }

  outputShapeInfo(shape);
  delete shape;

  return 0;
}
