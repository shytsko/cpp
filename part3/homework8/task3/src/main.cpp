/*Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.
Окно располагается на виртуальном экране монитора, размером 80 × 50 точек. У
окна есть несколько параметров, которые также задаются в пикселях: двумерные
координаты левого верхнего угла и размеры, ширина и высота. Ширина и высота при
этом не могут быть отрицательными, а координаты не могут выходить за область
экрана.

Пользователь взаимодействует с программой с помощью команд:

• Команда move принимает вектор, на который надо сместить окно на экране.
Сообщение с новыми координатами окна появляется на экране. • Команда resize
запрашивает из стандартного ввода новый размер окна. После изменения размера
сообщение с новым размером выводится на экране. • Команда display выводит
текущее изображение монитора в консоль. 0 — это пиксель вне области окна, 1 — с
окном. • Команда close закрывает окно, выход из программы.*/

#include "display.h"
#include "window.h"
#include <iostream>
#include <string>

int main() {
  Display display{80, 50};
  Window window{{5, 5}, 10, 5, &display};
  display.render();

  bool exitFlag = false;
  std::string command;
  while (!exitFlag) {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Enter command (move, resize, display, close) > ";
    std::cin >> command;
    if (command == "move") {
      int offsetX, offsetY;
      std::cout << "Enter offset (X Y) > ";
      std::cin >> offsetX >> offsetY;
      window.move({offsetX, offsetY});
      Vector2D newPosition = window.getPosition();
      std::cout << "New window coordinates have been set: "
                << newPosition.getX() << ", " << newPosition.getY()
                << std::endl;
    } else if (command == "resize") {
      int newWidth, newHeight;
      std::cout << "Enter new size (width height) > ";
      std::cin >> newWidth >> newHeight;
      window.resize(newWidth, newHeight);
      std::cout << "New window size have been set: " << window.getWidth()
                << ", " << window.getHeight() << std::endl;
    } else if (command == "display") {
      display.render();
    } else if (command == "close") {
      exitFlag = true;
    } else {
      std::cout << "Invalid command" << std::endl;
    }
  }

  return 0;
}
