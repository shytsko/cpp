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
#include <iostream>

Color inputColor(void) {
  std::cout << "Select color (1 - red, 2 - blue, 3 - green, other - none) > ";
  int i;
  std::cin >> i;
  return (i >= 1 && i <= 3) ? static_cast<Color>(i) : Color::None;
}

int main() {
  // Circle circle{{1, 2}, Color::Blue, 10.2};
  // Triangle triangle{{5, 6}, Color::Green, 5.5};
  // Rectangle rectanle{{4.4, 6.6}, Color::Red, 6.2, 8.8};
  // Square square{{2.2, 3.3}, Color::None, 15.2};

  Color c1 = inputColor();
  c1 = inputColor();

  c1 = inputColor();

  c1 = inputColor();

  return 0;
}
