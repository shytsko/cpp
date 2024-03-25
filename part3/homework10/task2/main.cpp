/*С помощью многопоточности реализуйте простую модель железнодорожного вокзала.
С трёх точек отправления в разное время отбывают три разных поезда с условными
обозначениями A, B, C. Все они идут на один и тот же вокзал и могут дойти до
него в разное время. На этом целевом вокзале единовременно может находиться
только один поезд. Остальные поезда должны ждать, пока уже занятое место
освободится. В начале программы пользователь последовательно вводит для каждого
поезда время в пути до вокзала (в секундах). После этого поезда начинают своё
движение за заданное количество времени. Как только поезд прибыл на вокзал, он
ожидает от пользователя команды depart, которая сигнализирует о его отбытии с
вокзала. По всем событиям (прибытие на вокзал, ожидание свободного места,
отбытие с вокзала) вместе с условным обозначением поезда выводятся сообщения в
консоль. Программа завершается, когда на вокзале побывают все три поезда.*/

#include <atomic>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex stationMutex;
std::mutex outputMutex;
std::atomic_bool departFlag = false;

void train(std::string id, int timeBeforeArrival) {
  std::this_thread::sleep_for(std::chrono::seconds(timeBeforeArrival));

  outputMutex.lock();
  std::cout << "Train " << id << " is waiting for free space" << std::endl;
  outputMutex.unlock();

  // Блокировка места на вокзале
  stationMutex.lock();

  outputMutex.lock();
  std::cout << "Train " << id << " arrived at the station" << std::endl;
  outputMutex.unlock();

  // Ожидание, пока диспетчер не устновит флаг на отправку
  while (!departFlag)
    std::this_thread::yield();

  // Перед отправкой снимаем флаг, чтобы следующий поезд не проехал без
  // остановки
  departFlag = false;
  stationMutex.unlock();

  outputMutex.lock();
  std::cout << "Train " << id << " left the station" << std::endl;
  outputMutex.unlock();
}

int main() {
  std::thread trainA(train, "A", 30);
  std::thread trainB(train, "B", 3);
  std::thread trainC(train, "C", 10);

  std::string command;
  int departCounter = 0;
  while (departCounter < 3) {
    std::cin >> command;
    if (command == "depart") {
      departFlag = true;
      while (departFlag)
        std::this_thread::yield();
      departCounter++;
    }
  }

  trainA.join();
  trainB.join();
  trainC.join();
  return 0;
}
