/*Реализуйте простой симулятор проведения медицинской операции у пациента.
Пользователь выступает в роли хирурга, который запрашивает инструменты у
ассистента и применяет их сообразно ситуации. Пользователь взаимодействует с
программой с помощью команд. Команды не имеют сложной встроенной логики: они
просто принимают нужные данные в качестве аргументов и выводят сообщения в
консоль о выполнении. Данные команд — это одна или две двумерные точки в формате
double с координатами X и Y соответственно. Команда scalpel — принимает на вход
две двумерные координаты начала и конца разреза или линии отсечения. При
выполнении в консоль выводится сообщение о том, что был сделан разрез между
введёнными координатами. Команда hemostat принимает на вход одну точку, в
которой требуется сделать зажим, о чём также сообщает в консоль. Команда
tweezer — пинцет, как и зажим, принимает одну точку для применения. Сообщение
об этом выводится в консоль. Команда suture — хирургическая игла, которая делает
шов между двумя указанными точками. Операция всегда начинается с команды scalpel
и заканчивается командой suture. Для окончания работы программы их
параметры-точки должны совпасть. Программу требуется реализовать именно с
помощью одного заголовочного файла и одного файла с исходным кодом (CPP). В
заголовочном файле должны находиться функции-инструменты. В основном файле —
основная логика программы, обработка ввода пользователя.*/

#include "point.h"
#include "surgeon.h"
#include <iostream>
#include <string>

#define CMD_SCALPEL "scalpel"
#define CMD_HEMOSTAT "hemostat"
#define CMD_TWEEZER "tweezer"
#define CMD_SUTURE "suture"

int main() {
  std::string command;
  bool operationStarted = false;
  bool operationCompleted = false;
  Point startOperationPoint;
  Point endOperationPoint;

  while (!operationCompleted) {
    std::cout << "Enter command (scalpel, hemostat, tweezer, suture): ";
    std::cin >> command;

    if (command == CMD_SCALPEL) {
      std::cout << "Enter start point: ";
      Point startPoint;
      std::cin >> startPoint;
      std::cout << "Enter end point: ";
      Point endPoint;
      std::cin >> endPoint;

      // Если это первая команда scalpel, устанавливается флаг начала операции и
      // сохраняются точки
      if (!operationStarted) {
        operationStarted = true;
        startOperationPoint = startPoint;
        endOperationPoint = endPoint;
        std::cout << "Operation started" << std::endl;
      }

      scalpel(startPoint, endPoint);

    } else {
      // Если операция еще не начата, все другие команды должны игнорироваться
      if (operationStarted) {
        if (command == CMD_HEMOSTAT) {
          std::cout << "Enter point: ";
          Point point;
          std::cin >> point;
          hemostat(point);
        } else if (command == CMD_TWEEZER) {
          std::cout << "Enter point: ";
          Point point;
          std::cin >> point;
          tweezer(point);
        } else if (command == CMD_SUTURE) {
          std::cout << "Enter start point: ";
          Point startPoint;
          std::cin >> startPoint;
          std::cout << "Enter end point: ";
          Point endPoint;
          std::cin >> endPoint;
          suture(startPoint, endPoint);
          // если точки совпадают с точками первого разреза, операция
          // завершается
          if (startPoint == startOperationPoint &&
              endPoint == endOperationPoint)
            operationCompleted = true;
        }
      } else {
        std::cout << "The operation has not yet started" << std::endl;
      }
    }
  }
  std::cout << "Operation completed" << std::endl;
  return 0;
}
